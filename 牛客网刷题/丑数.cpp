#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int GetUglyNumber(int index)
	{
		if (index < 7)
			return index;
		int p2 = 0, p3 = 0, p5 = 0;
		vector<int> vres;
		int factor = 1;
		vres.push_back(factor);
		while (vres.size()<index)
		{
			factor = min(vres[p2] * 2, min(vres[p3] * 3, vres[p5] * 5));
			if (vres[p2] * 2 == factor) p2++;
			if (vres[p3] * 3 == factor) p3++;
			if (vres[p5] * 5 == factor) p5++;
			vres.push_back(factor);
		}
		return factor;
	}
};