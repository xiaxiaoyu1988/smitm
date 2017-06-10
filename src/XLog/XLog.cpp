
#include <string>
#include <log4cplus/appender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/logger.h>
#include <log4cplus/layout.h>
#include <log4cplus/helpers/loglog.h>
#include <iostream>

#include "XLog.h"
#include "XConfig.h"

using namespace std;
using namespace log4cplus;


bool XLog::intFlag = false;

#define MAXBUFSIZE 1024

Logger XLog::GetInstance()
{
	tstring loggerName = tstring("Main");
	if (!intFlag)
	{

		string key = "logPath";
		string logPath;

		XConfig::GetInstance()->getValueByKey(key, (void*) &logPath, CONFIG_STRING);

		logPath.append("x.log");

		key = "logSize";
        int logSize = 0;
        XConfig::GetInstance()->getValueByKey(key, (void*) &logSize, CONFIG_INT);

		SharedAppenderPtr file_append(new RollingFileAppender(logPath.c_str(), logSize, 1));  // 200K max size

		auto_ptr<Layout> _layout(new PatternLayout("%D{%m/%d/%y %H:%M:%S,%Q} %p [%l] - %m%n"));

		Logger::getInstance(loggerName).addAppender(file_append);
		file_append->setLayout(_layout);


		auto_ptr<Layout> _layoutC(new PatternLayout("%D{%m/%d/%y %H:%M:%S,%Q} %p [%l] - %m%n"));
		SharedAppenderPtr console_append(new ConsoleAppender());

		Logger::getInstance(loggerName).addAppender(console_append);
		console_append->setLayout(_layoutC);

		key = "logLevel";
		int logLevel = 0;
		XConfig::GetInstance()->getValueByKey(key, (void*) &logLevel, CONFIG_INT);

		Logger::getInstance(loggerName).setLogLevel(logLevel);
		intFlag = true;
	}

	return Logger::getInstance(loggerName);
}




