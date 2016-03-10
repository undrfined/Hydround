#ifndef TestPlugin_H
#define TestPlugin_H

class TestPlugin {
	public:
		TestPlugin();
		virtual ~TestPlugin();
		virtual void enable();
		virtual void disable();
};
#endif /* TestPlugin_H */
