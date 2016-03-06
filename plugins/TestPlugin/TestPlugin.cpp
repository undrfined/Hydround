#include "TestPlugin.h"
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
cout << "TestPlugin enabled!" << endl;
}

void TestPlugin::disable(){
cout << "TestPlugin disabled." << endl;
}
