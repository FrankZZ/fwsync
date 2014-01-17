#pragma once
#include "CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "constants.h"

//#include <stdlib.h>

using namespace std;

namespace fwsync
{

	class GetCommandHandler : public CommandHandler
	{
		private:
			GetCommandHandler();
			GetCommandHandler(wstring);

		public:
			virtual void process(Socket* socket, vector<wstring>& params);
			virtual CommandHandler* clone();

		private:
			static GetCommandHandler m_getCmdHandler;
	};
}