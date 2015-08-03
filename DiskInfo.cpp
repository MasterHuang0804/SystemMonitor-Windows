#include "DiskInfo.h"

DiskInfo::DiskInfo()
	:C_FreeBytesAvailable(0),
	C_TotalNumberOfFreeBytes(0),
	C_TotalNumberOfBytes(0),
	ReadSpeed(0), WriteSpeed(0)
{
	DWORD DrvStrLen = GetLogicalDriveStrings(0, NULL);
	LPSTR DrvStr = (LPSTR)HeapAlloc(GetProcessHeap(), 0, DrvStrLen*sizeof(TCHAR));

	GetLogicalDriveStrings(DrvStrLen, DrvStr); //获取磁盘驱动器符号

	UINT DriveType = 0;
	INT i = 0;

	while (i < DrvStrLen)
	{

		DriveType = GetDriveType(DrvStr + i);

		if (DriveType == 3)							//DRIVE_FIXED
			LogicalDrive.push_back(DrvStr + i);		//容器存放磁盘的名称，如“C:\”

		i += 4;
	}
}

void DiskInfo::GetDefaultDriveFixedSize(char *c)
{
	BOOL Result = GetDiskFreeSpaceEx(c, (PULARGE_INTEGER)&C_FreeBytesAvailable,(PULARGE_INTEGER)&C_TotalNumberOfBytes,
										(PULARGE_INTEGER)&C_TotalNumberOfFreeBytes);
}

DOUBLE DiskInfo::CalculateDiskIOSpeedInPdh(const char *CounterPath)
{
	HQUERY query;
	PDH_STATUS status;
	
	status = PdhOpenQuery(NULL, NULL, &query);

	CheckPdhStatus(status, "Disk Open Query");

	HCOUNTER counter;
	counter = (HCOUNTER *)GlobalAlloc(GPTR, sizeof(HCOUNTER));
	
	status = PdhAddCounter(query, CounterPath, NULL, &counter);

	CheckPdhStatus(status, "Disk Add Counter");

	PdhCollectQueryData(query);

	Sleep(1000);

	PdhCollectQueryData(query);

	PDH_FMT_COUNTERVALUE pdhValue;
	DWORD dwValue;

	status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, &dwValue, &pdhValue);

	CheckPdhStatus(status, "Disk Get Value");

	PdhCloseQuery(query);	

	DOUBLE speed = pdhValue.doubleValue;

	return speed;
}

int DiskInfo::CheckPdhStatus(PDH_STATUS status,const string &str)
{
	if (status != ERROR_SUCCESS)
	{
		cout << str << " Failed" << endl;
		return -1;
	}
}

UINT64 DiskInfo::GetDiskReadSpeed()
{
	char *ReadSpeedCounterPath = "\\PhysicalDisk(_Total)\\Disk Read Bytes\/sec";

	ReadSpeed = CalculateDiskIOSpeedInPdh(ReadSpeedCounterPath);

	return ReadSpeed / 1024; //'KB'
}

UINT64 DiskInfo::GetDiskWriteSpeed()
{
	char *WriteSpeedCounterPath = "\\PhysicalDisk(_Total)\\Disk Write Bytes\/sec";

	WriteSpeed = CalculateDiskIOSpeedInPdh(WriteSpeedCounterPath);

	return WriteSpeed / 1024; //'KB'
}


UINT64 DiskInfo::GetDisk_C_TotalFixdSize()
{
	return C_TotalNumberOfBytes / DIV ;				//DIV=1024*1024
}

UINT64 DiskInfo::GetDisk_C_UsedFixedSize()
{
	return (C_TotalNumberOfBytes - C_FreeBytesAvailable) / DIV ;
}

vector<string> DiskInfo::GetLogicalDriveContainer()
{
	return LogicalDrive;
}

DiskInfo::~DiskInfo() 
{

}
