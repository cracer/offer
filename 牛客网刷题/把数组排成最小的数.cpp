#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string PrintMinNumber(vector<int> numbers)
	{
		int len = numbers.size();
		if (len == 0 || numbers.empty())
			return "";
		vector<string> res;
		for (auto &i : numbers)
			res.push_back(to_string(i));
		sort(res.begin(), res.end(),
			[](string &s1, string& s2) {return s1 + s2 < s2 + s1;});
		string tmpRes = "";
		for (auto &j : res)
			tmpRes += j;
		return tmpRes;

	}
};