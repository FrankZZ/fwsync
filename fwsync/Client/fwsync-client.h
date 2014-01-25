#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "../Shared/constants.h"
#include "../Shared/utility.h"
#include "../Shared/Models/socket.h"
#include "../Shared/Commands/CommandHandler.h"
#include "../Shared/Models/CommandFactory.h"
#include "../Shared/Models/SocketException.h"

namespace fwsync
{

	class Client
	{
		public:
			Client::Client();
			Client::~Client();

			void Client::connect(const char*, int);

		private:
			void Client::ReadFromSocket(Socket*);

	};

}