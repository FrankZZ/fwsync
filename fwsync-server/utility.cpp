#include "utility.h"

using namespace std;

namespace fwsync
{
	void strsplit(string str, vector<string> &tokens)
	{
		string buf;
		stringstream ss(str); // Insert the string into a stream

		while (ss >> buf)
			tokens.push_back(buf);
	}
}
