#pragma comment(lib,"pdh.lib")

#ifndef _CPU_INFO_IN_PDH_H
#define _CPU_INFO_IN_PDH_H

#include <iostream>
#include <Pdh.h>
#include <PdhMsg.h>
#include <Windows.h>
#include <string>

using namespace std;

class CpuInfoInPdh
{
public:
	CpuInfoInPdh();
	~CpuInfoInPdh();
	
	int GetCpuUsedRate();

	int CheckPdhStatus(PDH_STATUS, const string &);

private:
	int CpuUsedRate;
};

#endif