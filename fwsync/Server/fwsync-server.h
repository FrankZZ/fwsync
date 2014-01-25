#pragma once

#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
#include "../Shared/constants.h"
#include "../Shared/utility.h"
#include "../Shared/Models/Socket.h"
#include "../Shared/Commands/CommandHandler.h"
#include "../Shared/Models/CommandFactory.h"
#include "../Shared/Models/SocketException.h"

namespace fwsync
{
	class Server
	{
		private:
			void handle(Socket *socket);

		public:
			void listen(int iPort);
	};
}
