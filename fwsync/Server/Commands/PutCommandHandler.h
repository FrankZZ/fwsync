#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../../Shared/constants.h"
#include "../../Shared/Models/FileWriter.h"


//#include <stdlib.h>

using namespace std;

namespace fwsync
{

	class PutCommandHandler : public CommandHandler
	{
	private:
		PutCommandHandler();
		PutCommandHandler(string);

	public:
		virtual void process(Socket* socket, string szLine);
		virtual CommandHandler* clone();

	private:
		static PutCommandHandler m_putCmdHandler;
	};
}
