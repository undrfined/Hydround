
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Config.h>
#include <utils/Log.h>

#include <exception>
#include <fstream>
#include <iostream>

#include <utils/RapidXML/rx.h>
#include <utils/RapidXML/rxutils.h>

using namespace hydround::utils;
using namespace rapidxml;

Config::Config(char* p, bool c) : path(p), createIfNotExist(c), cfg(p) {
	update();
}

Config::~Config(){ }

void Config::update() {
	doc.parse<0>(cfg.data());
}

void Config::save() {
	std::ofstream stream(path);
	//stream >> doc;
	stream.close();
}

void Config::write(char* key, auto value) {
	xml_node<>* node = doc.allocate_node(node_element, key);
	node->append_attribute(value);
	doc.append_node(node);
}

const char* Config::read(char* key) {
		xml_node<>* node = doc.first_node(key);
		if(node)
			return node->value();
		else
			return 0;
}
