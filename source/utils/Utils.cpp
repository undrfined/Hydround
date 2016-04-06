
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Utils.h>

#include <iostream>
#include <string>
#include <sstream>

using namespace hydround::utils;
using std::string;
using std::istringstream;

inline void setColor(string colorStr) {
	#ifdef _WIN32
		#include <windows.h>
		int color;
		if(colorStr == "black")
				color = 0x00; else
		if(colorStr == "blue")
				color = 0x01; else
		if(colorStr == "green")
				color = 0x02; else
		if(colorStr == "cyan")
				color = 0x03; else
		if(colorStr == "red")
				color = 0x04; else
		if(colorStr == "magenta")
				color = 0x05; else
		if(colorStr == "brown")
				color = 0x06; else
		if(colorStr == "lightgrey")
				color = 0x07; else
		if(colorStr == "darkgrey")
				color = 0x08; else
		if(colorStr == "lightblue")
				color = 0x09; else
		if(colorStr == "lightgreen")
				color = 0x0A; else
		if(colorStr == "lightcyan")
				color = 0x0B; else
		if(colorStr == "lightred")
				color = 0x0C; else
		if(colorStr == "lightmagenta")
				color = 0x0D; else
		if(colorStr == "yellow")
				color = 0x0E; else color = 0x0F;
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, color);
	#else
		string c;
		if(colorStr == "black")
			c = "30"; else
		if(colorStr == "red")
			c = "31"; else
		if(colorStr == "green")
			c = "32"; else
		if(colorStr == "brown")
			c = "33"; else
		if(colorStr == "blue")
			c = "34"; else
		if(colorStr == "magenta")
			c = "35"; else
		if(colorStr == "cyan")
			c = "36"; else
		if(colorStr == "lightgrey")
			c = "37"; else
		if(colorStr == "darkgrey")
			c = "30;1"; else
		if(colorStr == "lightred")
			c = "31;1"; else
		if(colorStr == "lightgreen")
			c = "32;1"; else
		if(colorStr == "yellow")
			c = "33;1"; else
		if(colorStr == "lightblue")
			c = "34;1"; else
		if(colorStr == "lightmagenta")
			c = "35;1"; else
		if(colorStr == "lightcyan")
			c = "36;1"; else
		c = "37;1";
		std::cout << "\033[" << c << "m";
	#endif
}

inline void resetColor() {
	std::cout << "\033[0m";
}

inline int stoi(string str) {
	istringstream stream(str);
	int integer;
	if (stream >> integer)
		return integer;
	else {
		throw std::exception();
	}
}