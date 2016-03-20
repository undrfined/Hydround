
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Utils.h>

#include <iostream>
#include <locale>

using namespace hydround::utils;

char* Utils::toLower(const char* upper) {
	std::locale loc;
	char* lower;
	for(int i = 0; i < sizeof(upper); i++)
		lower += std::tolower(upper[i], loc);
	return lower;
}

void Utils::setColor(const char* colorStr) {
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
		char* c;
		if(colorStr == "black")
				c = (char*) "30"; else
		if(colorStr == "red") {
				std::cout << "error";
				c = (char*) "31"; }else
		if(colorStr == "green")
				c = (char*) "32"; else
		if(colorStr == "brown")
				c = (char*) "33"; else
		if(colorStr == "blue")
				c = (char*) "34"; else
		if(colorStr == "magenta")
				c = (char*) "35"; else
		if(colorStr == "cyan")
				c = (char*) "36"; else
		if(colorStr == "lightgrey")
				c = (char*) "37"; else
		if(colorStr == "darkgrey")
				c = (char*) "30;1"; else
		if(colorStr == "lightred")
				c = (char*) "31;1"; else
		if(colorStr == "lightgreen")
				c = (char*) "32;1"; else
		if(colorStr == "yellow")
				c = (char*) "33;1"; else
		if(colorStr == "lightblue")
				c = (char*) "34;1"; else
		if(colorStr == "lightmagenta")
				c = (char*) "35;1"; else
		if(colorStr == "lightcyan")
				c = (char*) "36;1"; else c = (char*) "37;1";
		std::cout << "\033[" << c << "m";
	#endif
}