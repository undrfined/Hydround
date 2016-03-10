
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Log.h>

#include <iostream>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/format.hpp>

using namespace boost::posix_time;
using namespace boost;
using namespace std;

const char* Log::getFormat(const char* mode, const int color, const void* text){
	format f("\033[3%1%m[%5%] [Hydround] [%2%/%3%] -> %4%\033[0m\n");
	f % color % (char*) prefix % (char*)mode % (char*) text % second_clock::local_time().time_of_day();
	return f.str().c_str();
}
void Log::error(const void* s){
	cout << getFormat("ERROR", 1, s);
}
void Log::fatal(const void* s){
	cout << getFormat("FATAL", 1, s);
}
void Log::warning(const void* s){
	cout << getFormat("WARNING", 4, s);
}
void Log::info(const void* s){
	cout << getFormat("INFO", 7, s);
}
void Log::debug(const void* s){
	cout << getFormat("DEBUG", 3, s);
}
