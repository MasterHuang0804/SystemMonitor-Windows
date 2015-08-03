#pragma comment(lib,"pdh.lib")

#ifndef _NET_INTERFACE_INFO_H
#define _NET_INTERFACE_INFO_H

#include <iostream>
#include <cstdint>
#include <tchar.h>
#include <Pdh.h>
#include <PdhMsg.h>
#include <string>
#include <Windows.h>

using namespace std;

class NetInterfaceInfo
{
public:
	NetInterfaceInfo();
	~NetInterfaceInfo();

	double   CalculateNetIOSpeed(const char *);

	UINT64 GetNetSendSpeed();
	UINT64 GetNetReceivedSpeed();

	int CheckPdhStatus(PDH_STATUS, string);

private:

	UINT64 TransmittedSpeed;
	UINT64 ReceivedSpeed;

	HQUERY query;
	HCOUNTER counter;
	PDH_STATUS status;
};

#endif
