#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../../Shared/constants.h"
#include "../../Shared/Models/FileReader.h"


//#include <stdlib.h>

using namespace std;

namespace fwsync
{

	class GetCommandHandler : public CommandHandler
	{
	private:
		GetCommandHandler();
		GetCommandHandler(string);

	public:
		virtual void process(Socket* socket, string szLine);
		virtual CommandHandler* clone();

	private:
		static GetCommandHandler m_getCmdHandler;
	};
}
