#pragma once

#ifndef _HTTP_CLIENT_H
#define _HTTP_CLIENT_H

#include <Poco/Net/HTTPSession.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/URI.h>

#include <iostream>
#include <string>
#include <json/json.h>
#include <json/value.h>

#include "GenerateJsonData.h"

using namespace std;
using namespace Poco::Net;

class HttpClient
{
public:
	HttpClient();
	~HttpClient();

	void HttpSendPerformanceData();
};

#endif
