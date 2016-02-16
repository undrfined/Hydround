
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <boost/asio/basic_datagram_socket.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/udp.hpp>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>

#include "utils/Config.h"
#include "utils/Log.h"
#include "utils/Translation.h"

class Package;

using namespace boost::asio;

using namespace std;
typedef unsigned char byte;
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
int main(){
	Log logger(Translation->getTranslation("server"));
	Config cfg("ServerConfig.json");
	logger.info(Translation->getTranslation("loadingServer"));
	int port = cfg.readInt("ServerPort", 19131);
	char binding[32] = { };
	sprintf(binding, t.getTranslation("binding", "Binding on port %d...").c_str(), port);
	logger.info(string(binding));
	io_service service;
	char buff[1024];
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), port));
	while (true) {
		ip::udp::endpoint sender;
		int bytes = sock.receive_from(buffer(buff), sender);
		//Package incoming(buff[0], buff);
		for (const char* p = buff; *p; ++p)
		    {
		        printf("%02x", *p);
		    }
		stringstream ss;
		ss << buff;
		std::vector<std::string> arr = split(ss.str(), 0x00);
		long pingId = atol(arr[0].c_str());
      ss.str("");//
		ss << (char) 0x1c << pingId << (char) 0x00 << (char) 0xff << (char) 0xff << (char) 0x00 << (char) 0xfe << (char) 0xfe << (char) 0xfe << (char) 0xfe << (char) 0xfd << (char) 0xfd << (char) 0xfd << (char) 0xfd << (char) 0x12 << (char) 0x34 << (char) 0x56 << (char) 0x78 << "MCPE;§6§l » Hydround server §6«;41;0.14.0;0;10";
		sock.send_to(buffer(ss.str()), sender);
	}


}