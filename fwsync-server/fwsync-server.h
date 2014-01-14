#pragma once

#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
#include "constants.h"
#include "utility.h"
#include "socket.h"
#include "CommandHandler.h"
#include "CommandFactory.h"

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
