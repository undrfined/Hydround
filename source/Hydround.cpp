
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <stdio.h>
#include <dlfcn.h>
#include <cstring>
#include <string>
#include <exception>

#include <plugin/Plugin.h>
#include <Hydround.h>
#include <utils/Log.h>
#include <utils/Config.h>

using namespace hydround;
using namespace hydround::utils;
using namespace hydround::plugin;

extern "C" Hydround* __createHydroundObject() {
	return new Hydround;
}

Hydround::Hydround() {	}

void Hydround::start(){
	Log log("Server");
	log.info("Loading server...");
	Config cfg("/data/data//com.n0n3m4.droidc/files/server/Server.xml");
	int port;
	try {
		port = cfg.readInt("Port");
	} catch(std::exception e) {
		port = 19132;
	}
	log.info("Binding on port " + port);
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
	return;
}