#pragma once

#ifndef _MEMORY_INFO_H
#define _MEMORY_INFO_H

#include <iostream>
#include <Windows.h>

using namespace std;

#define DIV 1024   // MB/KB
#define WIDTH 7

class MemoryInfo
{
public:
	MemoryInfo();
	~MemoryInfo();

	MEMORYSTATUSEX statex;

	DWORDLONG GetTotalPhysMemSize();
	DWORDLONG GetAvailPhysMemSize();
	DWORDLONG GetUsedPhysMemSize();

	DWORDLONG GetTotalPageFileSize();
	DWORDLONG GetAvailPageFileSize();
	DWORDLONG GetTotalVirtMemSize();
	DWORDLONG GetAvailVirtMemSize();

	DWORD GetMemoryUsedRate();

private:

	DWORDLONG TotalPhysMemSize;		//总共物理内存
	DWORDLONG AvailPhysMemSize;		//可用物理内存
	DWORDLONG TotalPageFileSize;	//全部页面文件
	DWORDLONG AvailPageFileSize;	//剩余页面文件
	DWORDLONG TotalVirtMemSize;		//全部虚拟内存
	DWORDLONG AvailVirtMemSize;		//可用虚拟内存

	DWORD MemUsedRate;
};

#endif

