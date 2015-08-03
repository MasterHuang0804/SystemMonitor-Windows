#include "HttpClientByCurl.h"


HttpClientByCurl::HttpClientByCurl()
{
	CURL *curl = curl_easy_init();
	CURLcode res;

	Config *config = new Config();

	string url = config->GetHttpPostUrl();

	struct curl_slist *list = NULL;

	const char *contentType = "application/x-www-form-urlencoded";

	GenerateJsonData *json = new GenerateJsonData();
	Json::Value performance = json->GetPerformanceData();

	string data = "data=" + performance.toStyledString();
	 
	{
		list = curl_slist_append(list, contentType);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER,list);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

		res = curl_easy_perform(curl);

		curl_slist_free_all(list);
	}

	curl_easy_cleanup(curl);

}


HttpClientByCurl::~HttpClientByCurl()
{
}
