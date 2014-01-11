#pragma once
#include <string>
#inc
#include <iostream>

class Server
{
	void strsplit(std::string line);

	public:
		void handle(std::Socket *socket);
};