#include <iostream>
#include "XConfig.h"
#include "XPub.h"
#include "XHttpClient.h"

using namespace std;
int main()
{
	if(XConfig::GetInstance()->init("./etc/smitm.json") != X_SUCCESS)
	{
		cerr<<"XConfig init failed"<<endl;
	}
	string key = "logPath";
	string logPath;
	XConfig::GetInstance()->getValueByKey(key, (void*)&logPath, CONFIG_STRING);
	cout<<logPath<<endl;

	key = "logLevel";
	int logLevel;
	XConfig::GetInstance()->getValueByKey(key, (void*)&logLevel, CONFIG_INT);
	cout<<logLevel<<endl;

	key = "log";
	bool log;
	XConfig::GetInstance()->getValueByKey(key, (void*)&log, CONFIG_BOOL);
	cout<<(log?"true":"false")<<endl;

	XHttpClient c;

    return 0;
}
