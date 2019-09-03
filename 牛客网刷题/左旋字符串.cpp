#include <string>
using namespace std;

class Solution
{
public:
	string LeftRotateString(string str,int n)
	{
		string tmp = "";
		tmp = str.substr(0, n);
		str.erase(0, n);
		str = str + tmp;
		return str;
	}
};