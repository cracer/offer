#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int getSum(int num)
	{
		int sum = 0;
		while (num!=0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}

	bool hasPath(int threshold,int rows,int cols,int row,int col,bool* visited)
	{
		if (row >= 0 && row < rows&&col >= 0 && col < cols&&getSum(row) + getSum(col) <= threshold
			&& visited[row*cols + col] == 0)
			return true;
		else
			return false;
	}

	int searchMove(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		int cnt = 0;
		if(hasPath(threshold,rows,cols,row,col,visited))
		{
			visited[row*cols + col] = true;
			cnt = 1 + searchMove(threshold, rows, cols, row-1, col, visited)
					+ searchMove(threshold, rows, cols, row, col-1, visited)
					+ searchMove(threshold, rows, cols, row+1, col, visited)
					+ searchMove(threshold, rows, cols, row, col+1, visited);
		}
		return cnt;
	}

	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;
		bool* visited = new bool[rows*cols];
		for (int i = 0; i < rows * cols; i++)
			visited[i] = false;
		int tmp = searchMove(threshold, rows, cols, 0, 0, visited);
		delete[] visited;
		return tmp;
	}
};