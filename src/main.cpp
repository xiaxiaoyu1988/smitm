#include <iostream>
#include "XConfig.h"
#include "XPub.h"
#include "XHttpClient.h"
#include "XLog.h"

using namespace std;
int main()
{
	if(XConfig::GetInstance()->init("./etc/smitm.json") != X_SUCCESS)
	{
		cerr<<"XConfig init failed"<<endl;
		return X_FAILED;
	}
	string x="1";
	cout<<"aaaaa"<<endl;
	X_WARN("aa:"<<x);
	X_DEBUG("aa");
	cout<<"bbbbbb"<<endl;
	XHttpClient c;

	cout<<"emd"<<endl;

    return 0;
}
