#include "utility.h"

namespace fwsync
{
	void strsplit(std::string str, std::vector<std::string> &tokens)
	{
		std::string buf;
		std::stringstream ss(str); // Insert the string into a stream

		while (ss >> buf)
			tokens.push_back(buf);
	}
}
