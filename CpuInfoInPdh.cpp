#include "CpuInfoInPdh.h"


CpuInfoInPdh::CpuInfoInPdh()
	:CpuUsedRate(0)
{
	HQUERY query;
	HCOUNTER counter;
	PDH_STATUS status;

	status = PdhOpenQuery(NULL, NULL, &query);

	CheckPdhStatus(status, "Cpu Open Query");

	counter = (HCOUNTER *)GlobalAlloc(GPTR, sizeof(HCOUNTER));

	status = PdhAddCounter(query, LPCSTR("\\Processor Information(_Total)\\% Processor Time"), NULL, &counter);
	CheckPdhStatus(status, "Cpu Add Counter");

	PDH_FMT_COUNTERVALUE pdhValue;
	DWORD dwValue;

	PdhCollectQueryData(query);

	Sleep(1000);

	PdhCollectQueryData(query);

	status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE | PDH_FMT_NOCAP100, &dwValue, &pdhValue);

	CheckPdhStatus(status, "Cpu Get Counter");

	CpuUsedRate = (int)pdhValue.doubleValue ;

	PdhCloseQuery(query);
}

int CpuInfoInPdh::CheckPdhStatus(PDH_STATUS status, const string &str)
{
	if (status != ERROR_SUCCESS)
	{
		cout << str << " Failed" << endl;
		return -1;
	}
}

int CpuInfoInPdh::GetCpuUsedRate()
{
	return CpuUsedRate;
}

CpuInfoInPdh::~CpuInfoInPdh()
{
}
