
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
#include <exception>

#include <plugin/Plugin.h>
#include <Hydround.h>
#include <utils/Log.h>
#include <utils/Config.h>
#include <leveldb/db.h>

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
	Log log((char*) "Server");
	log.info("Loading server...");
	Config cfg((char*) "Server.xml");
	int port;
	try {
		port = cfg.readInt((char*) "Port");
	} catch(std::exception e) {
		port = 19132;
	}
	log.info(port);
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "db.ldb", &db);
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
