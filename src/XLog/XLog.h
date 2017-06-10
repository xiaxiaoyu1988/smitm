
#pragma once

#include <string>
#include <iomanip>


#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
using namespace log4cplus;
using log4cplus::Logger;
using namespace std;


#define X_FATAL(x)        LOG4CPLUS_FATAL(XLog::GetInstance(), x)
#define X_ERROR(x)        LOG4CPLUS_ERROR(XLog::GetInstance(), x)
#define X_WARN(x)         LOG4CPLUS_WARN(XLog::GetInstance(), x)
#define X_INFO(x)         LOG4CPLUS_INFO(XLog::GetInstance(), x)
#define X_DEBUG(x)        LOG4CPLUS_DEBUG(XLog::GetInstance(), x)
#define X_TRACE(x)        LOG4CPLUS_TRACE(XLog::GetInstance(), x)




class XLog{
private:
	XLog();
	~XLog();

public:
	static log4cplus::Logger GetInstance();

private:
	static bool intFlag;
};
