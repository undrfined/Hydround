
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
#include <cstring>

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
		if(strcmp(colorStr, "black") == 0)
				color = 0x00; else
		if(strcmp(colorStr, "blue") == 0)
				color = 0x01; else
		if(strcmp(colorStr, "green") == 0)
				color = 0x02; else
		if(strcmp(colorStr, "cyan") == 0)
				color = 0x03; else
		if(strcmp(colorStr, "red") == 0)
				color = 0x04; else
		if(strcmp(colorStr, "magenta") == 0)
				color = 0x05; else
		if(strcmp(colorStr, "brown") == 0)
				color = 0x06; else
		if(strcmp(colorStr, "lightgrey") == 0)
				color = 0x07; else
		if(strcmp(colorStr, "darkgrey") == 0)
				color = 0x08; else
		if(strcmp(colorStr, "lightblue") == 0)
				color = 0x09; else
		if(strcmp(colorStr, "lightgreen") == 0)
				color = 0x0A; else
		if(strcmp(colorStr, "lightcyan") == 0)
				color = 0x0B; else
		if(strcmp(colorStr, "lightred") == 0)
				color = 0x0C; else
		if(strcmp(colorStr, "lightmagenta") == 0)
				color = 0x0D; else
		if(strcmp(colorStr, "yellow") == 0)
				color = 0x0E; else color = 0x0F;
		HANDLE console;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, color);
	#else
		char* c;
		if(strcmp(colorStr, "black") == 0)
			c = (char*) "30"; else
		if(strcmp(colorStr, "red") == 0)
			c = (char*) "31"; else
		if(strcmp(colorStr, "green") == 0)
			c = (char*) "32"; else
		if(strcmp(colorStr, "brown") == 0)
			c = (char*) "33"; else
		if(strcmp(colorStr, "blue") == 0)
			c = (char*) "34"; else
		if(strcmp(colorStr, "magenta") == 0)
			c = (char*) "35"; else
		if(strcmp(colorStr, "cyan") == 0)
			c = (char*) "36"; else
		if(strcmp(colorStr, "lightgrey") == 0)
			c = (char*) "37"; else
		if(strcmp(colorStr, "darkgrey") == 0)
			c = (char*) "30;1"; else
		if(strcmp(colorStr, "lightred") == 0)
			c = (char*) "31;1"; else
		if(strcmp(colorStr, "lightgreen") == 0)
			c = (char*) "32;1"; else
		if(strcmp(colorStr, "yellow") == 0)
			c = (char*) "33;1"; else
		if(strcmp(colorStr, "lightblue") == 0)
			c = (char*) "34;1"; else
		if(strcmp(colorStr, "lightmagenta") == 0)
			c = (char*) "35;1"; else
		if(strcmp(colorStr, "lightcyan") == 0)
			c = (char*) "36;1"; else
		c = (char*) "37;1";
		std::cout << "\033[" << c << "m";
	#endif
}

void Utils::resetColor() {
	std::cout << "\033[0m";
}