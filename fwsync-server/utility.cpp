#include "utility.h"

using namespace std;

namespace fwsync
{
	void strsplit(string str, vector<string> &tokens, char delim)
	{
		string buf;
		stringstream ss(str); // Insert the string into a stream

		while (getline(ss, buf, delim))
			tokens.push_back(buf);
	}
}
