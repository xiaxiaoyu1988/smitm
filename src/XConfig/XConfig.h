/*
 * XConfig.h
 *
 *  Created on: Jun 6, 2017
 *      Author: root
 */

#ifndef SRC_XCONFIG_XCONFIG_H_
#define SRC_XCONFIG_XCONFIG_H_

#include "XPub.h"
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;
using namespace std;

class XConfig {
private:
	XConfig();
	virtual ~XConfig();
private:
	static XConfig *instance;
	Document doc;
public:
	static XConfig* GetInstance();
	int    init(const char *configPath);
	int    getValueByKey(string &key, void *value, int VALUE_TYPE);
};

#endif /* SRC_XCONFIG_XCONFIG_H_ */
