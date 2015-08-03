#pragma once
#ifndef _SYSTEM_INFO_H
#define _SYSTEM_INFO_H

#include <string>
#include <iostream>
#include <time.h>
#include <Poco/Environment.h>
#include <Windows.h>


using namespace std;

class SystemInfo
{
public:
	SystemInfo();
	~SystemInfo();

	INT		GetProcessorCount();
	string	GetSystemName();
	string	GetSystemArchitecture();

	LONG	GetTimeGMT();
};

#endif