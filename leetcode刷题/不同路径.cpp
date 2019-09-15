#include <vector>
using namespace std;
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int> > v(n, vector<int>(m, 0));
		for (int i = 0; i < m; i++)
			v[0][i] = 1;
		for (int i = 0; i < n; i++)
			v[i][0] = 1;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				v[j][i] = v[j - 1][i] + v[j][i - 1];
			}
		}
		return v[n - 1][m - 1];
	}
};