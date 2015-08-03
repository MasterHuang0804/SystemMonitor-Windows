//#define _WIN32_WINNT   0x0501
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>

#include "config.h"
#include "HttpClientByCurl.h"

using namespace std;

int main(int argc, char **argv)
{
	while (1)
	{
		Sleep(1000);

		HttpClientByCurl *client = new HttpClientByCurl();		
	}
	
	return 0;
}