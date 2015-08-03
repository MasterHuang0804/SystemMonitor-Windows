#include "MemoryInfo.h"

MemoryInfo::MemoryInfo()
	:TotalPhysMemSize(0), AvailPhysMemSize(0),
	TotalPageFileSize(0), AvailPageFileSize(0), 
	TotalVirtMemSize(0), AvailVirtMemSize(0),
	MemUsedRate(0)
{
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	TotalPhysMemSize = statex.ullTotalPhys;
	AvailPhysMemSize = statex.ullAvailPhys;
	
	TotalPageFileSize = statex.ullTotalPageFile;
	AvailPageFileSize = statex.ullAvailPageFile;

	TotalVirtMemSize = statex.ullTotalVirtual;
	AvailVirtMemSize = statex.ullAvailVirtual;
	
	MemUsedRate = statex.dwMemoryLoad; //内存使用率
}

DWORDLONG MemoryInfo::GetTotalPhysMemSize()
{
	return TotalPhysMemSize / DIV / DIV ;
}

DWORDLONG MemoryInfo::GetAvailPhysMemSize()
{
	return AvailPhysMemSize / DIV / DIV ;
}

DWORDLONG MemoryInfo::GetUsedPhysMemSize()
{
	return (TotalPhysMemSize - AvailPhysMemSize) / DIV / DIV;
}

DWORDLONG MemoryInfo::GetTotalPageFileSize()
{
	return TotalPageFileSize / DIV / DIV;
}

DWORDLONG MemoryInfo::GetAvailPageFileSize()
{
	return AvailPageFileSize / DIV / DIV;
}

DWORDLONG MemoryInfo::GetTotalVirtMemSize()
{
	return TotalVirtMemSize / DIV / DIV;
}

DWORDLONG MemoryInfo::GetAvailVirtMemSize()
{
	return AvailVirtMemSize / DIV / DIV;
}

DWORD MemoryInfo::GetMemoryUsedRate()
{
	return MemUsedRate;
}

MemoryInfo::~MemoryInfo()
{

}
