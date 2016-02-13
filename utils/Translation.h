
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#ifndef TRANSLATION_H_
#define TRANSLATION_H_

#include <iostream>
#include <sstream>
#include "../Resources.h"
#include "Config.h"
using namespace std;

class Translation {
private:
	string lang;
	string path = Resources::getTranslationFile();
public:
	Translation() : lang(Resources::getDefaultLanguage()){

	}

	string getTranslation(string key, string def){
		stringstream ss;
		ss << lang << "." << key;
		  try
		    {
		        boost::property_tree::ptree pt;
		        boost::property_tree::read_json(path, pt);
		        return pt.get<string>(ss.str());
		    }
		    catch (std::exception const& e)
		    {
		    	return def;
		    }
		return def;
	}
};



#endif /* TRANSLATION_H_ */
