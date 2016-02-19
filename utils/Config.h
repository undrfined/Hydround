
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>
#include <boost/property_tree/xml_parser.hpp>
#include <cassert>
#include <boost/property_tree/ptree.hpp>
using namespace std;

class Config {
	private:
		string path;
		boost::property_tree::ptree pt;
	public:
		Config(string s) : path(s){
			boost::property_tree::read_xml(path, pt);
		}
		int readInt(string key){
			return pt.get<int>(key);
		}
		string readString(string key){
			return pt.get<string>(key);
		}
};
#endif /* CONFIG_H_ */