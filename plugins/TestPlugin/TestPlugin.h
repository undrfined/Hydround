#ifndef TEST_PLUGIN_H_
#define TEST_PLUGIN_H_
//#include "../../plugin/Plugin.h"

class TestPlugin {
public:
	TestPlugin();
	virtual ~TestPlugin();
	virtual void enable();
	virtual void disable();
};
#endif
