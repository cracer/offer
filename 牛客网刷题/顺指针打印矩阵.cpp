#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> printMatrix(vector<vector<int> > matrix) 
	{

		int row1 = 0, row2 = matrix.size();
		int col1 = 0, col2 = matrix[0].size();
		vector<int> result;

		while (true)
		{
			//从左到右打印
			for (int i = col1;i < col2;i++)
			{
				result.push_back(matrix[row1][i]);
			}
			row1++;
			if (row1 >= row2) break;
			//从上往下
			for (int i = row1;i < row2;i++)
			{
				result.push_back(matrix[i][col2 - 1]);
			}
			col2--;
			if (col1 >= col2) break;
			//从右往左
			for (int i = col2 - 1;i >= col1;i--)
			{
				result.push_back(matrix[row2 - 1][i]);
			}
			row2--;
			if (row1 >= row2) break;
			//从下往上
			for (int i = row2 - 1;i >= row1;i--)
			{
				result.push_back(matrix[i][col1]);
			}
			col1++;
			if (col1 >= col2) break;
		}

		return result;
	}
};
