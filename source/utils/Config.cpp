
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Config.h>
#include <utils/Utils.h>
#include <utils/Log.h>

#include <exception>
#include <fstream>
#include <cstring>
#include <string>

#include <utils/RapidXML/rx.h>
#include <utils/RapidXML/rxutils.h>

using namespace hydround::utils;
using namespace rapidxml;
using std::string;

Config::Config(string p, bool c) : path(p), createIfNotExist(c), cfg(p.c_str()) {
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

void Config::write(string key, auto value) {
	xml_node<>* node = doc.allocate_node(node_element, key.c_str());
	node->append_attribute(value);
	doc.append_node(node);
}

string Config::readString(string key) {
		xml_node<>* node = doc.first_node(key.c_str());
		if(node)
			return node->value();
		else
			throw std::exception();
}

bool Config::readBool(string key) {
		if(readString(key.c_str()) == "true")
			return true;
		else
			return false;
}

int Config::readInt(string key) {
	try {
		return stoi(readString(key.c_str()));
	} catch(std::exception e) {
		throw std::exception();
	}
}