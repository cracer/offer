#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> Permutation(string str)
	{
		vector<string> res;
		int len = str.length();
		if (len == 0) return res;
		Permutations(res, str, 0, len);
		return res;
	}

	void Permutations(vector<string> &result,string str,int index,int len)
	{
		if(index==len)
		{
			result.push_back(str);
			return;
		}
		for (int i = index; i < len; i++)
		{
			if (i != index && str[i] == str[index])
				continue;
			swap(str[i], str[index]);
			Permutations(result, str, index + 1, len);
		}
	}
};