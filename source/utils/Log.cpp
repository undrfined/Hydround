
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
#include <string>

using namespace hydround::utils;
using hydround::utils::Log;
using std::cout;
using std::string;
using std::endl;

string Log::getFormat(string mode, string color, string message){
	setColor(color);
	string format;
	format.reserve(string("[18:00:00] [Hydround] [").size() + prefix.size() + string("/").size() + mode.size() + string("] -> ").size() + message.size());
	return format;
}
void Log::error(string message){
	cout << getFormat("ERROR", "red", message);
	resetColor();
}
void Log::fatal(string message){
	cout << getFormat("FATAL", "lightred", message);
	resetColor();
}
void Log::warning(string message){
	cout << getFormat("WARNING", "yellow", message);
	resetColor();
}
void Log::info(string message){
	cout << getFormat("INFO", "white", message);
	resetColor();
}
void Log::debug(string message){
	cout << getFormat("DEBUG", "darkgrey", message);
	resetColor();
}
void Log::raw(string message){
	cout << message;
}