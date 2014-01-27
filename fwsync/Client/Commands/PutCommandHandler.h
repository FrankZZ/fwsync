#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../../Shared/constants.h"
#include "../../Shared/Models/SocketException.h"
#include <signal.h>
#include "../../Shared/Models/FileReader.h"

using namespace std;

namespace fwsync
{

	class PutCommandHandler : public CommandHandler
	{
		private:
			PutCommandHandler();
			PutCommandHandler(string);

		public:
			virtual void process(Socket* socket, vector<string>& params);
			virtual CommandHandler* clone();

		private:
			static PutCommandHandler m_putCmdHandler;
	};
	void interrupt(int param);
}