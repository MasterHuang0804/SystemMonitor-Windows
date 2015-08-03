#include "MemoryInfoInPdh.h"


MemoryInfoInPdh::MemoryInfoInPdh()
	:TotalPhysicsMemSize(0),
	UsedPhysicsMemSize(0),
	AvailPhysicsMemSize(0)
{
	HCOUNTER counter;
	PDH_STATUS status;
	HQUERY query;

	status = PdhOpenQuery(NULL, NULL, &query);

	CheckPDHStatus(status, "Mem Open Query");
	
	counter = (HCOUNTER *)GlobalAlloc(GPTR, sizeof(HCOUNTER));

	status = PdhAddCounter(query, LPCSTR("\\Memory\\Available MBytes"), NULL, &counter);

	CheckPDHStatus(status, "Mem Add Counter");
	
	PdhCollectQueryData(query);

	PDH_FMT_COUNTERVALUE pdhValue;
	DWORD dwValue;

	status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, &dwValue, &pdhValue);

	CheckPDHStatus(status, "Mem Get Value");

	AvailPhysicsMemSize = pdhValue.doubleValue;

	PdhCloseQuery(query);
}

int MemoryInfoInPdh::CheckPDHStatus(PDH_STATUS status, string str)
{
	if (status != ERROR_SUCCESS)
	{
		cout<< str << " Failed" << endl;
		return -1;
	}
}
UINT64 MemoryInfoInPdh::GetTotalPhysicsSize()
{
	return TotalPhysicsMemSize;
}

UINT64 MemoryInfoInPdh::GetAvailPhysicsSize()
{
	return AvailPhysicsMemSize;
}

UINT64 MemoryInfoInPdh::GetUsedPhysicsSize()
{
	return UsedPhysicsMemSize;
}

MemoryInfoInPdh::~MemoryInfoInPdh()
{

}
