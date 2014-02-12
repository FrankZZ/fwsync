#include "fwsync-client.h"

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "../Shared/utility.h"
#include <vector>
#include <string>

using namespace fwsync;

void askConnect(Client& client)
{
	cout << "Please type [host] [port]" << endl;

	string szLine;

	while (getline(std::cin, szLine))
	{
		if (szLine.length() == 0)
			continue;

		vector<std::string> params;

		strsplit(szLine, params, ' ');

		if (params.size() != 2)
		{
			cout << "Syntax error" << endl;
			continue;
		}

		client.connect(params[0].c_str(), stoi(params[1]));

	}
}

int main()
{	
	Client client = Client();

	while (1)
	{
		try
		{
			askConnect(client);
		}
		catch (SocketException& ex)
		{
			std::cout << "Connection lost..." << endl;
		}
		catch (invalid_argument& ex)
		{
			std::cout << "Invalid argument" << endl;
		}
		catch (out_of_range& ex)
		{
			std::cout << "Port out of range" << endl;
		}
		catch (runtime_error& ex)
		{
			std::cout << ex.what() << endl;
		}
	}

	return 0;
}