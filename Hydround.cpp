
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
	char magic[16] = { 0x00, 0xff, 0xff, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfd, 0xfd, 0xfd, 0xfd, 0x12, 0x34, 0x56, 0x78 };
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
		cout << bytes << "|" << endl;
		for(int i = 0; i < 1024; i++){
			cout << buff[i];
		}
		cout << endl;
		switch(buff[0]){
			case (char) 0x01:
				int pingId[8] = { (int) buff[1], (int) buff[2], (int) buff[3], (int) buff[4], (int) buff[5], (int) buff[6], (int) buff[7], (int) buff[8] };
				stringstream send;
				send << (char) 0x1c << pingId << 22345 << magic << "MCPE;LOL;45;0.14;0;10";
				log.debug("MOTD");
				sock.send_to(buffer(send.str()), sender);
			break;
		}
	}
	return;
}
