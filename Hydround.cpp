
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
#include <cstdio>
#include <string>
#include <vector>

#include "plugin/Plugin.h"
#include "Hydround.h"
using namespace std;
extern "C" Hydround* create_object() {
return new Hydround;
}
extern "C" void destroy_object( Hydround* object ) {
	delete object;
	}

Hydround::Hydround() {

}

void Hydround::start(){
	void* handle = dlopen("./plugins/TestPlugin.so", RTLD_LAZY);
if(!handle){
fprintf(stderr, "Error loading TestPlugin: %s\n", dlerror());
dlclose(handle);
}else{
Plugin* (*create)();
		create = (Plugin* (*)())dlsym(handle, "__createPluginObject");
		Plugin* p = (Plugin*)create();
		p->enable();
		p->disable();
}
/*Translation t;
	Log logger(t.getTranslation("server"));
	Config cfg("Server.xml");
	logger.info(t.getTranslation("loadingServer"));
	int port = cfg.readInt("ServerPort");
	char binding[32] = { };
	sprintf(binding, t.getTranslation("binding").c_str(), port);
	logger.info(string(binding));
	io_service service;
	char buff[1024];
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), port));
	while (true) {
		ip::udp::endpoint sender;
		int bytes = sock.receive_from(buffer(buff), sender);
		stringstream ss;
		ss << buff;
		std::vector<std::string> arr = split(ss.str(), 0x00);
		long pingId = atol(arr[0].c_str());
		ss.str("");
		cout << pingId;
		ss << 0x1c << pingId << 0x00 << 0xff << 0xff << 0x00 << 0xfe << 0xfe << 0xfe << 0xfe << 0xfd << 0xfd << 0xfd << 0xfd << 0x12 << 0x34 << 0x56 << 0x78 << "MCPE;§6§l » Hydround server §6«;41;0.14.0;0;10";
		sock.send_to(buffer(ss.str()), sender);
	}

*/
}
