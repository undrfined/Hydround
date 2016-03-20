
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
	log.error("Loading server...");
	Config cfg((char*) "Server.xml");
	const char* port = cfg.read((char*) "Port");
	if(port)
		log.info(port);
	else
		log.warning("ERROR");
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
