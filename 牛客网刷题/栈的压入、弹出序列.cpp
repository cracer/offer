#include <vector>
using namespace std;


class Solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
			return false;
		vector<int> tempStack;
		for (int i = 0, j = 0; i < pushV.size();i++)
		{
			tempStack.push_back(pushV[i]);
			while (j < popV.size() && tempStack.back() == popV[j])
			{
				tempStack.pop_back();
				j++;
			}
		}
		return tempStack.empty();
	}
};