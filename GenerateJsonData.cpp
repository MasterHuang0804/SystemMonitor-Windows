#include "GenerateJsonData.h"


GenerateJsonData::GenerateJsonData()
{

}

Json::Value GenerateJsonData::GetPerformanceData()
{ 
	CpuInfoInPdh *cpu = new CpuInfoInPdh();

	MemoryInfo	*mem = new MemoryInfo();

	SystemInfo *sys = new SystemInfo();

	DiskInfo	*disk = new DiskInfo();
	disk->GetDefaultDriveFixedSize();

	NetInterfaceInfo *net = new NetInterfaceInfo();
	
	Json::Value root;
	
	Json::Value json_mem;
	Json::Value json_disk;
	Json::Value json_net;

	root["time"] = Json::Value((Json::Value::UInt64)sys->GetTimeGMT());
	
	root["vmid"] = "windows-vmid";
	
	root["cpu"] = Json::Value((Json::Value::UInt)cpu->GetCpuUsedRate());

	json_mem["total"] = Json::Value((Json::Value::UInt64)mem->GetTotalPhysMemSize());
	json_mem["used"] = Json::Value((Json::Value::UInt64)mem->GetUsedPhysMemSize());

	root["mem"] = json_mem;
		
	json_disk["total"] = Json::Value((Json::Value::UInt64)disk->GetDisk_C_TotalFixdSize());
	json_disk["used"] = Json::Value((Json::Value::UInt64)disk->GetDisk_C_UsedFixedSize());
	json_disk["read"] = Json::Value((Json::Value::UInt64)disk->GetDiskReadSpeed());
	json_disk["write"] = Json::Value((Json::Value::UInt64)disk->GetDiskWriteSpeed());

	root["disk"] = json_disk;

	json_net["in"] = Json::Value((Json::Value::UInt64)net->GetNetReceivedSpeed());
	json_net["out"] = Json::Value((Json::Value::UInt64)net->GetNetSendSpeed());

	root["net"] = json_net;

	
	Json::StyledWriter styled_writer;
	cout << styled_writer.write(root) << endl;
		
	return root;
}


GenerateJsonData::~GenerateJsonData()
{

}
