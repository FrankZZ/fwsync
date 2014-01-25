#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../../Shared/constants.h"
#include "../../Shared/Models/SocketException.h"
#include <signal.h>
#include "../../Shared/Models/FileWriter.h"

using namespace std;

namespace fwsync
{

	class GetCommandHandler : public CommandHandler
	{
		private:
			GetCommandHandler();
			GetCommandHandler(string);
			

		public:
			virtual void process(Socket* socket, vector<string>& params);
			virtual CommandHandler* clone();

		private:
			static GetCommandHandler m_getCmdHandler;
	};
	void interrupt(int param);
}