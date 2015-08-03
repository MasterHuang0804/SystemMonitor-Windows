#pragma once

#include <iostream>
#include <json/json.h>
#include <json/value.h>

#include "CpuInfoInPdh.h"
#include "MemoryInfo.h"
#include "SystemInfo.h"
#include "DiskInfo.h"
#include "NetInterfaceInfo.h"

using namespace std;  

class GenerateJsonData
{
public:
	GenerateJsonData();
	~GenerateJsonData();

	Json::Value GetPerformanceData();
};

