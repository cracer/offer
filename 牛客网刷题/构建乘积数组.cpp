#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> multiply(const vector<int>& A)
	{
		int len = A.size();
		vector<int> vtmp(len, 1);
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (i == j)
					continue;
				vtmp[j] *= A[i];
			}
		}
		return vtmp;
	}

};