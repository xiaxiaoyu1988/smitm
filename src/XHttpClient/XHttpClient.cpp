/*
 * XHttpClient.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: root
 */

#include "XHttpClient.h"
#include "XPub.h"
#include "XConfig.h"

#include <openssl/ssl.h>
#include <string>

using namespace std;

XHttpClient::XHttpClient() {
	string key = "backend";
	string backend;
	XConfig::GetInstance()->getValueByKey(key, (void*)&backend, CONFIG_STRING);

	if(backend.compare("https") == 0)
	{
		backend_server_type = SERVER_HTTPS;
	}
	else
	{
		backend_server_type = SERVER_HTTP;
	}

	base = NULL;
}

XHttpClient::~XHttpClient() {
	// TODO Auto-generated destructor stub
}

int XHttpClient::serverInit()
{
	base = event_base_new();
	if (!base) {

		return X_FAILED;
	}
	return X_SUCCESS;
}
