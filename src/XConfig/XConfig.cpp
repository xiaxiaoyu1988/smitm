/*
 * XConfig.cpp
 *
 *  Created on: Jun 6, 2017
 *      Author: root
 */

#include "XConfig.h"
#include <iostream>
#include <fstream>
#include <sstream>

XConfig * XConfig::instance = NULL;


XConfig::XConfig() {
	// TODO Auto-generated constructor stub

}

XConfig::~XConfig() {
	// TODO Auto-generated destructor stub
}

XConfig* XConfig::GetInstance()
{
	if(instance == NULL)
	{
		instance = new XConfig();
	}

	return instance;
}


int  XConfig::init(const char *configPath)
{
	if(configPath == NULL)
	{
		return X_FAILED;
	}
	cout<<"Config path:"<<configPath<<endl;
	ifstream in(configPath, ifstream::in);
	if(!in.is_open())
	{
		return X_FAILED;
	}
	ostringstream buf;
	buf<<in.rdbuf();

	doc.Parse(buf.str().c_str());
	return X_SUCCESS;
}

int    XConfig::getValueByKey(string &key, void *value, int VALUE_TYPE)
{
	if(key.empty())
	{
		return X_FAILED;
	}

	if(&doc != NULL)
	{
		if(doc.HasMember(key.c_str()))
		{
			switch(VALUE_TYPE)
			{
				case CONFIG_STRING:
				{
					((string *)value)->assign(doc[key.c_str()].GetString());
					break;
				}
				case CONFIG_INT:
				{
					*((int*)value) = doc[key.c_str()].GetInt();
					break;
				}
				case CONFIG_BOOL:
				{
					*((bool*)value) = doc[key.c_str()].GetBool();
					break;
				}
				default:
				{
					cout<<"Not support config type:"<<VALUE_TYPE<<endl;
				}
			}
			return X_SUCCESS;
		}
	}

	return X_FAILED;
}
