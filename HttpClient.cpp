#include "HttpClient.h"


HttpClient::HttpClient()
{
	
}

void HttpClient::HttpSendPerformanceData()
{
	string url = "http://192.168.1.200:8000/postNodeStatus.php";

	Poco::URI uri(url);

	string path = uri.getPath();

	HTTPClientSession session(uri.getHost(), uri.getPort());
	session.setKeepAlive(true);

	HTTPRequest req(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_1);
	req.setContentType("application/x-www-form-urlencoded");
	req.setKeepAlive(true);
	
	GenerateJsonData *json = new GenerateJsonData();
	Json::Value performance = json->GetPerformanceData();

	string databody = performance.toStyledString();
	string data = "data=" + databody;
	
	req.setContentLength(data.length());
	
	//ostream &myOstream = session.sendRequest(req);
	
	//myOstream <<data;

	/*HTTPResponse  rep(HTTPResponse::HTTPStatus::HTTP_OK);
	
	istream &myIstream = session.receiveResponse(rep);

	cout<<myIstream.rdbuf() << endl;
	*/

	cout << "send ok" << endl;
}


HttpClient::~HttpClient()
{
}
