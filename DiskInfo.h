#ifndef _DISK_INFO_H
#define _DISK_INFO_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <Pdh.h>
#include <PdhMsg.h>
#include <Windows.h>

#pragma comment(lib,"pdh.lib")

using namespace std;

#define DIV 1024*1024 ;

class DiskInfo
{
public:
	DiskInfo();
	~DiskInfo();
	
	void   GetDefaultDriveFixedSize(char *c = "c:\\");
	
	double	CalculateDiskIOSpeedInPdh(const char *);

	int		CheckPdhStatus(PDH_STATUS, const string&);

	UINT64 GetDisk_C_TotalFixdSize();
	UINT64 GetDisk_C_UsedFixedSize();

	vector<string> GetLogicalDriveContainer();

	UINT64 GetDiskReadSpeed();
	UINT64 GetDiskWriteSpeed();

private:
	UINT64 C_FreeBytesAvailable;
	UINT64 C_TotalNumberOfBytes;
	UINT64 C_TotalNumberOfFreeBytes;

	double ReadSpeed;
	double WriteSpeed;

	vector<string> LogicalDrive;


};

#endif
