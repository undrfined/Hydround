
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

// HYS - Hydround Starter.
// HYS will be start Hydround server.
#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include "Hydround.h"
using namespace std;
int main(){
	void* handle = dlopen("./hydround.so", RTLD_LAZY);
	if(!handle){
		fprintf(stderr, "dlopen failure: %s\n", dlerror()); 
		return 1;
	}
	Hydround* (*create)();
	void (*destroy)(Hydround*);
	create = (Hydround* (*)())dlsym(handle, "create_object");
	destroy = (void (*)(Hydround*))dlsym(handle, "destroy_object");
	Hydround* server = (Hydround*)create();
	server->start();
	destroy(server);
	return 0;
}
