#include "GetCommandHandler.h"
using namespace std;

namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(std::string("get"));

	GetCommandHandler::GetCommandHandler(std::string sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(Socket* socket, std::vector<std::string>& params)
	{
		ifstream isFile(params[1], ifstream::binary);

		if (!isFile.is_open())
		{
			throw("cannot open file");
		}

		char* buff = new char[BUFFERSIZE + 1];

		streampos end;

		isFile.seekg(0, isFile.end);
		end = isFile.tellg();
		isFile.seekg(0, isFile.beg);
		
		// Send total size to client
		socket->writeline(to_string(end).c_str());

		while (isFile.good())
		{
			isFile.get(buff, BUFFERSIZE);
			socket->write(buff);
		}

		delete[] buff;
	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}