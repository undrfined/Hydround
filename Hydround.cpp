
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
#include <utils/Config.h>

#include <boost/asio/basic_datagram_socket.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/udp.hpp>

using namespace boost::asio;
using namespace hydround;
using namespace hydround::utils;
using namespace hydround::plugin;

extern "C" Hydround* create_object() {
	return new Hydround;
}
extern "C" void destroy_object(Hydround* object) {
	delete object;
}

Hydround::Hydround() {	}

void Hydround::start(){
	using std::cout;
	Log log((char*) "Server");
	int port;
	char* serverName;
	char* motd;
	int maxPlayers;
	char* lang;
	try{
		Config cfg((char*) "Server.xml");
		port = cfg.read<int>((void*) "ServerPort");
		serverName = cfg.read<char*>((void*) "ServerName");
		motd = cfg.read<char*>((void*) "ServerMotd");
		maxPlayers = cfg.read<int>((void*) "MaxPlayers);
	} catch(FileNotExistException e) {
		log.warning("Config file not found, creating new one.");
	} catch(CreateFileException e) {
		log.fatal("Config file cannot be created! Stopping server...");
		return;
	} catch(ReadException e) {
		log.info(e.what());
		return;
	}
	log.info("Loading server...");
/*	void* handle = dlopen("plugins/TestPlugin.so", RTLD_LAZY);
	if(!handle){
		log.error(dlerror());
		dlclose(handle);
	}else{
		Plugin* (*create)();
		create = (Plugin* (*)())dlsym(handle, "__createPluginObject");
		Plugin* p = create();
		log.info("TestPlugin enabled!");
 		p->enable();
	}*/
	/*io_service service;
	char buff[1024];
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), port));
	while (1) {
		ip::udp::endpoint sender;
		int bytes = sock.receive_from(buffer(buff), sender);
		switch(buff[0]){
			case (char) 0x01:
				log.debug("MOTD");
				//sock.send_to(buffer(send.str()), sender);
			break;
		}
	}*/
	return;
}
