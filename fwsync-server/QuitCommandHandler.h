#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"

using namespace std;

namespace fwsync
{

	class QuitCommandHandler : public CommandHandler
	{
	private:
		QuitCommandHandler();
		QuitCommandHandler(wstring);

	public:
		virtual void process(Socket*, vector<wstring>&);
		virtual CommandHandler* clone();

	private:
		static QuitCommandHandler m_quitCmdHandler;
	};
}
