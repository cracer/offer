#include <memory>
using namespace std;

class Solution
{
public:
	bool hasPathCore(char* matrix, int rows, int cols, char* str, int row, int col, bool* visited)
	{
		if (*str == '\0')
			return true;
		bool hasPath = false;// 不满足条件直接返回false

	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
			return false;
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				if(hasPathCore(matrix,rows,cols,str,row,col,visited))
				{
					return true;
				}
			}
		}
		return false;
	}


};