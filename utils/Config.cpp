
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

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp> 

using namespace boost::property_tree;
using namespace hydround::utils;

Config::Config(char *p, bool c) : path(p), createIfNotExist(c) {
	try {
		read_xml(path, tree);
	} catch(const ptree_error &e) {
		try {
			throw FileNotExistException();
			std::ofstream file(path);
			file.close();
		} catch(std::exception e) {
			throw CreateFileException();
		}
	}
}
Config::~Config(){ }
void Config::update() {
	try {
		read_xml(path, tree);
	} catch(const ptree_error &e) {
		throw UpdateException();
	}
}
void Config::save(){
	try {
		write_xml(path, tree);
	} catch(const ptree_error &e) {
		throw SaveException();
	}
}

void Config::write(void* key, void* value){
	tree.put((char*) key, (char*) value);
}

template<typename T> T Config::read(void* key){
	try {
		return tree.get<T>((char*) key);
	} catch(const ptree_error &e) {
		throw ReadException((char*) e.what());
	}
}
template int Config::read<int>(void*);
template char* Config::read<char*>(void*);
template long Config::read<long>(void*);
template short Config::read<short>(void*);
template float Config::read<float>(void*);
template double Config::read<double>(void*);
template bool Config::read<bool>(void*);
template char Config::read<char>(void*);