#include "config.h"

Config::Config()
{

	ifstream file("config.ini");

	string data;

	string s;
	 
	while (getline(file, s))
	{
		data += s;
	}

	AnalysisConfigFile(data);
}

int Config::AnalysisConfigFile(const string &str)
{
	Json::Reader reader;
	Json::Value json_object;

	if (!reader.parse(str, json_object))
	{
		cout << "Rarse Json Data Failed" << endl;
		return -1;
	}

	PostUrl = json_object["PostUrl"].asString();

	return 0;
}

string Config::GetHttpPostUrl()
{
	return PostUrl;
}

Config::~Config()
{

} 