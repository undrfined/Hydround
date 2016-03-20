
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#ifndef Config_H
#define Config_H

#include <utils/Log.h>

#include <utils/RapidXML/rx.h>
#include <utils/RapidXML/rxutils.h>

namespace hydround {
	namespace utils {
		
		class Config {
			private:
				bool createIfNotExist;
				char *path;
				rapidxml::xml_document<> doc;
				rapidxml::file<> cfg;
			public:
				Config(char *p, bool c = true);
				~Config();
				void update();
				void save();
				const char* read(char* key);
				void write(char* key, auto value);
		};

	}

}
#endif /* Config_H */
