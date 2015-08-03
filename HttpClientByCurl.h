#pragma comment(lib,"libcurl.lib")

#ifndef _HTTP_CLIENT_BY_CURL_H
#define _HTTP_CLIENT_BY_CURL_H

#include <iostream>
#include <curl/curl.h>
#include <json/json.h>
#include <json/value.h>

#include "GenerateJsonData.h"
#include "config.h"

using namespace std;

class HttpClientByCurl
{
public:
	HttpClientByCurl();
	~HttpClientByCurl();
};

#endif

