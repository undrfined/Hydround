
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <stdio.h>
#include <dlfcn.h>
#include <iostream>

#include <plugin/Plugin.h>
#include <Hydround.h>
#include <utils/Log.h>

#include <boost/asio/basic_datagram_socket.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/udp.hpp>

using namespace boost::asio;
using namespace std;

extern "C" Hydround* create_object() {
	return new Hydround;
}
extern "C" void destroy_object(Hydround* object) {
	delete object;
}

Hydround::Hydround() {	}

void Hydround::start(){
	Log log((char *) "Server");
	log.info("Loading server...");
	log.info("TestPlugin loading...");
	void* handle = dlopen("plugins/TestPlugin.so", RTLD_LAZY);
	if(!handle){
		log.error("Error loading TestPlugin.");
		dlclose(handle);
	}else{
		Plugin* (*create)();
		create = (Plugin* (*)())dlsym(handle, "__createPluginObject");
		Plugin* p = create();
		log.info("TestPlugin enabled!");
 		p->enable();
	}
	log.info("Binding on port 19132...");
	io_service service;
	char buff[1024];
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), 19132));
	while (1) {
		ip::udp::endpoint sender;
		int bytes = sock.receive_from(buffer(buff), sender);
		switch(buff[0]){
			case (char) 0x01:
				log.debug("MOTD");
				//sock.send_to(buffer(send.str()), sender);
			break;
		}
	}
	return;
}
