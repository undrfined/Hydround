
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#ifndef Config_H
#define Config_H

#include <boost/property_tree/ptree.hpp>
#include <utils/Log.h>
#include <exception>

namespace hydround {
	namespace utils {
	// TODO move exceptions implementation to .cpp file
		class FileNotExistException : public std::exception {
			virtual const char* what() const throw() {
				return "File not exist.";
			} 
		};
		
		class CreateFileException : public std::exception {
			virtual const char* what() const throw() {
				return "Cannot create file.";
			} 
		};
		
		class ReadException : public std::exception {
		public:
			char* error;
			ReadException(char* err) : error(err){
			
			}
			virtual const char* what() const throw() {
				return error;
			} 
		};
		
		class SaveException : public std::exception {
			virtual const char* what() const throw() {
				return "Cannot save file.";
			} 
		};
		
		class UpdateException : public std::exception {
			virtual const char* what() const throw() {
				return "Cannot update tree.";
			} 
		};
		
		class Config {
			private:
				bool createIfNotExist;
				char *path;
				boost::property_tree::ptree tree;
			public:
				Config(char *p, bool c = true);
				~Config();
				void save();
				void update();
				template <typename T> T read(void* key);
				void write(void* key, void* value);
		};

	}

}
#endif /* Config_H */
