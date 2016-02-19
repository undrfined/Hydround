#include "Log.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include "Translation.h"
#include "Config.h"

		void Log::replaceAll(std::string& str, const std::string& from, const std::string& to) {
		    if(from.empty())
		        return;
		    size_t start_pos = 0;
		    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		        str.replace(start_pos, from.length(), to);
		        start_pos += to.length();
		    }
		}
		string Log::getCurrentTime(const string format){
			struct tm * timeNowTm;
			time_t timeNow;
			time(&timeNow);
			timeNowTm = localtime(&timeNow);
			stringstream ss;
			ss << setfill('0') << format;
			string curtime = ss.str();
			ss.str(string());
			ss << setfill('0') << setw(2) << timeNowTm->tm_hour;
			replaceAll(curtime, "H", ss.str());
			ss.str(string());
			ss << setfill('0') << setw(2) << timeNowTm->tm_min;
			replaceAll(curtime, "i", ss.str());
			ss.str(string());
			ss << setfill('0') << setw(2) << timeNowTm->tm_sec;
			replaceAll(curtime, "s", ss.str());
			return curtime;
		}
		string Log::getFormat(const string mode, const int color){
			stringstream ss;
			ss << setfill('0') << "\033[3" << color << "m" << "[" << getCurrentTime("H:i:s") << "] [Hydround] [" << prefix << "/"<< mode <<"] -> %s\033[0m" <<endl;
			return ss.str();
		}
		void Log::error(const string s){
			Translation t;
			printf(getFormat(t.getTranslation("error"), 1).c_str(), s.c_str());
		}
		void Log::fatal(const string s){
			Translation t;
			printf(getFormat(t.getTranslation("fatal"), 1).c_str(), s.c_str());
		}
		void Log::warning(const string s){
			Translation t;
			printf(getFormat(t.getTranslation("warning"), 4).c_str(), s.c_str());
		}
		void Log::info(const string s){
			Translation t;
			printf(getFormat(t.getTranslation("info"), 7).c_str(), s.c_str());
		}
		void Log::debug(const string s){
			Translation t;
			printf(getFormat(t.getTranslation("debug"), 3).c_str(), s.c_str());
		}	 
