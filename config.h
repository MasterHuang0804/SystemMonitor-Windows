#ifndef _CONFIG_H
#define _CONFIG_H

#include <iostream>
#include <fstream>
#include <string>
#include <json/json.h>
#include <json/value.h>

using namespace std;

class Config
{
public:
	Config();
	~Config();

	int AnalysisConfigFile(const string &);

	string GetHttpPostUrl();

private:
	string PostUrl;
};

#endif