#pragma comment(lib,"pdh.lib")

#ifndef _MEMORY_INFO_IN_PDH_H
#define _MEMORY_INFO_IN_PDH_H

#include <iostream>
#include <Pdh.h>
#include <PdhMsg.h>
#include <string>

using namespace std;

class MemoryInfoInPdh
{
public:
	MemoryInfoInPdh();
	~MemoryInfoInPdh();

	UINT64 GetTotalPhysicsSize();
	UINT64 GetAvailPhysicsSize();
	UINT64 GetUsedPhysicsSize();

	int		CheckPDHStatus(PDH_STATUS, string);

private:
	UINT64 TotalPhysicsMemSize;
	UINT64 AvailPhysicsMemSize;
	UINT64 UsedPhysicsMemSize;
};

#endif

