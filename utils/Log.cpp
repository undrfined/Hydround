
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Log.h>
#include <utils/Utils.h>

#include <iostream>
#include <sstream>

using namespace std;
using namespace hydround::utils;

template<class T> const char* Log::getFormat(const char* mode, const char* color, T message){
	Utils::setColor(color);
	cout << color;
	stringstream ss;
	ss << "[18:00:00] [Hydround] [" << prefix << "/" << mode << "] -> " << message << endl;
	Utils::setColor("white");
	return ss.str().c_str();
}
template<class T> void Log::error(T message){
	cout << getFormat("ERROR", "red", message);
}
template<class T> void Log::fatal(T message){
	cout << getFormat("FATAL", "lightred", message);
}
template<class T> void Log::warning(T message){
	cout << getFormat("WARNING", "yellow", message);
}
template<class T> void Log::info(T message){
	cout << getFormat("INFO", "white", message);
}
template<class T> void Log::debug(T message){
	cout << getFormat("DEBUG", "darkgrey", message);
}
template<class T> void Log::raw(T message){
	cout << message;
}

template const char* Log::getFormat(const char*, const char*, const char*);
template const char* Log::getFormat(const char*, const char*, const int);

template void Log::info(const char*);
template void Log::info(const int);

template void Log::error(const char*);
template void Log::error(const int);

template void Log::debug(const char*);
template void Log::debug(const int);

template void Log::fatal(const char*);
template void Log::fatal(const int);

template void Log::warning(const char*);
template void Log::warning(const int);