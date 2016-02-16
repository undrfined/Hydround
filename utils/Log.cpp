#include "Log.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include "Translation.h"
#include "Config.h"
#include "../Resources.h"

class Log{
	private:
		string prefix;
	public:
		Log(string p) : prefix(p){	}
		void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		    if(from.empty())
		        return;
		    size_t start_pos = 0;
		    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		        str.replace(start_pos, from.length(), to);
		        start_pos += to.length();
		    }
		}
		string getCurrentTime(const string format){
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
		string getFormat(const string mode, const int color){
			stringstream ss;
			ss << setfill('0') << "\033[3" << color << "m" << "[" << getCurrentTime("H:i:s") << "] [Hydround] [" << prefix << "/"<< mode <<"] -> %s\033[0m" <<endl;
			return ss.str();
		}
		void error(const string s){
			Translation t;
			printf(getFormat(string(t.getTranslation("error", "ERROR")), 1).c_str(), s.c_str());
		}
		void fatal(const string s){
			Translation t;
			printf(getFormat(string(t.getTranslation("fatal", "FATAL")), 1).c_str(), s.c_str());
		}
		void warning(const string s){
			Translation t;
			printf(getFormat(string(t.getTranslation("warning", "WARNING")), 3).c_str(), s.c_str());
		}
		void info(const string s){
			Translation t;
			printf(getFormat(string(t.getTranslation("info", "INFO")), 7).c_str(), s.c_str());
		}
		void debug(const string s){
			Translation t;
			printf(getFormat(string(t.getTranslation("debug", "DEBUG")), 3).c_str(), s.c_str());
		}	 
};