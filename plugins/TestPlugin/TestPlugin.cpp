#include "TestPlugin.h"
#include <utils/Log.h>
#include <iostream>
using namespace std;
extern "C" TestPlugin* __createPluginObject(){
return new TestPlugin;
}
TestPlugin::TestPlugin(){

}
TestPlugin::~TestPlugin(){

}

void TestPlugin::enable(){
Log log("TestPlugin");
log.info("I'm really enabled!");
}

void TestPlugin::disable(){

}
