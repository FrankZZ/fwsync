#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace fwsync
{
	void strsplit(string str, vector<string> &tokens, char delim);
	void strsplit(string str, vector<string> &tokens, char delim, int iLimit);
}
