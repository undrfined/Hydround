#include "TestPlugin.h"
#include <utils/Log.h>
#include <iostream>
#include <utils/Config.h>

using namespace std;
using namespace hydround::utils;

extern "C" TestPlugin* __createPluginObject(){
	return new TestPlugin;
}

TestPlugin::TestPlugin(){ }
TestPlugin::~TestPlugin(){ }

void TestPlugin::enable(){
	Log log((char*) "TestPlugin");
//	Config cfg((char*) "../Server.xml");
//	cfg.read<int>("ServerPort");
}

void TestPlugin::disable(){ }
