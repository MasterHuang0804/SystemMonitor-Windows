#include "NetInterfaceInfo.h"

NetInterfaceInfo::NetInterfaceInfo()
	:TransmittedSpeed(0), ReceivedSpeed(0)
{
	
}

double NetInterfaceInfo::CalculateNetIOSpeed(const char *CounterPath)
{
	PDH_STATUS status = PdhOpenQuery(NULL, NULL, &query);

	CheckPdhStatus(status, "Net Open Query");

	HCOUNTER counter;
	counter = (HCOUNTER *)GlobalAlloc(GPTR, sizeof(HCOUNTER));

	status = PdhAddCounter(query, CounterPath, NULL, &counter);
	
	CheckPdhStatus(status, "Net Add Counter");

	PDH_FMT_COUNTERVALUE pdhValue;
	DWORD dwValue;

	PdhCollectQueryData(query);

	Sleep(1000);

	PdhCollectQueryData(query);

	status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE,&dwValue, &pdhValue);

	CheckPdhStatus(status, "Net Get Value");

	double speed = pdhValue.doubleValue;
	
	PdhCloseQuery(query);

	return speed;
}

int NetInterfaceInfo::CheckPdhStatus(PDH_STATUS status, string str)
{
	if (status != ERROR_SUCCESS)
	{
		cout << str << " Failed" << endl;
		return -1;
	}
}

UINT64 NetInterfaceInfo::GetNetSendSpeed()
{
	char *SendCounterPath = "\\Network Interface(*)\\Bytes Sent\/sec";

	double  SendSpeed = CalculateNetIOSpeed(SendCounterPath);

	return SendSpeed / 1024;	//'KB'
}

UINT64 NetInterfaceInfo::GetNetReceivedSpeed()
{
	char *ReceiveCounterPath = "\\Network Interface(*)\\Bytes Received\/sec";

	double ReceiveSpeed = CalculateNetIOSpeed(ReceiveCounterPath);

	return ReceiveSpeed / 1024;		//'KB'
}

NetInterfaceInfo::~NetInterfaceInfo()       
{

}
