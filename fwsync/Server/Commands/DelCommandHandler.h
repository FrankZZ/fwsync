#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "time.h"
#include "../../Shared/Models/Directory.h"
#include <stdio.h>

using namespace std;

namespace fwsync
{

	class DelCommandHandler : public CommandHandler
	{
	private:
		DelCommandHandler();
		DelCommandHandler(string);

	public:
		virtual void process(Socket*, string);
		virtual CommandHandler* clone();

	private:
		static DelCommandHandler m_delCmdHandler;
	};
}
