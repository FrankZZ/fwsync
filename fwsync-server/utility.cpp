#include "utility.h"

using namespace std;

namespace fwsync
{
	void wstrsplit(wstring str, vector<wstring> &tokens)
	{
		wstring buf;
		wstringstream ss(str); // Insert the string into a stream

		while (ss >> buf)
			tokens.push_back(buf);
	}
}
