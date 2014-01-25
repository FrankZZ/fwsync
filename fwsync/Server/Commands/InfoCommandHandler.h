#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "time.h"

using namespace std;

namespace fwsync
{

	class InfoCommandHandler : public CommandHandler
	{
	private:
		InfoCommandHandler();
		InfoCommandHandler(string);

	public:
		virtual void process(Socket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static InfoCommandHandler m_infoCmdHandler;
	};
}
