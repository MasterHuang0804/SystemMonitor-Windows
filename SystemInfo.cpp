#include "SystemInfo.h"

SystemInfo::SystemInfo()
{

}

INT SystemInfo::GetProcessorCount()
{
	return Poco::Environment::processorCount();
}

string SystemInfo::GetSystemName()
{
	return Poco::Environment::osDisplayName();
}

string SystemInfo::GetSystemArchitecture()
{
	return Poco::Environment::osArchitecture();
}

LONG SystemInfo::GetTimeGMT()
{
	const time_t t = time(NULL);

	//LONG T = (LONG)t;

	return (LONG)t;
}
SystemInfo::~SystemInfo()
{

}