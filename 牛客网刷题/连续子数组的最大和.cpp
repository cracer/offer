#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int FindGreatSumOfSubArray(vector<int> array)
	{
		int len = array.size();
		if (len <= 1) return array[0];
		int tmpMax = array[0];
		int resMax = array[0];
		for (int i = 1; i < len; i++)
		{
			tmpMax = max(tmpMax + array[i], array[i]);
			if (tmpMax >= resMax)
				resMax = tmpMax;
		}
		return resMax;
	}
};