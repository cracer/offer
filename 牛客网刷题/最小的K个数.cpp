#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> result;
		if (k <= 0 || input.size() <= 0 || k > input.size())
			return result;
		sort(input.begin(), input.end());
		int i = 0;
		while (i < k)
		{
			result.push_back(input[i]);
			i++;
		}
		return result;
	}
};