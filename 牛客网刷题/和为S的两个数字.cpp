#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum)
	{
		vector<int> result;
		int len = array.size();
		int start = 0;
		int end = len - 1;
		while (start < end)
		{
			if(array[start]+array[end]==sum)
			{
				result.push_back(array[start]);
				result.push_back(array[end]);
				return result;
			}
			if (array[start] + array[end] > sum)
				end--;
			if (array[start] + array[end] < sum)
				start++;
		}
		return result;
	}
};