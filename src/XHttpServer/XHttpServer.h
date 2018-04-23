/*
 * XHttpClient.h
 *
 *  Created on: Jun 7, 2017
 *      Author: root
 */

#ifndef SRC_XHTTPCLIENT_XHTTPCLIENT_H_
#define SRC_XHTTPCLIENT_XHTTPCLIENT_H_

#include <event2/bufferevent_ssl.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/http.h>

class XHttpClient {
public:
	XHttpClient();
	virtual ~XHttpClient();

	int serverInit();
	int server();

private:
	int backend_server_type;
	struct event_base *base;
};

#endif /* SRC_XHTTPCLIENT_XHTTPCLIENT_H_ */
