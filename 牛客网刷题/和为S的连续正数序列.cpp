#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int> > res;
		int begin = 1;
		int num = 1;
		int addNum = 1;
		while (addNum < sum)
		{
			num += 1;
			addNum += num;
			if(addNum == sum)
			{
				vector<int> v;
				for (int i = begin; i <= num; i++)
				{
					v.push_back(i);
				}
				res.push_back(v);
				begin += 1;
				addNum = begin;
				num = begin;
			}
			if(addNum>sum)
			{
				begin += 1;
				addNum = begin;
				num = begin;
			}
		}
		return res;

	}
};