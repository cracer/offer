#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, const char* str, 
		int& pathlength, bool* visited)
	{
		////一定注意开头两个判定的顺序，如果str已经全部监测了，那么就直接返回true，不需要进行下一步检测
		if (str[pathlength] == '\0')
			return true;
		bool hasPath = false;// 不满足条件直接返回false
		//需要进一步检测才检查状态
		if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[pathlength]&&!visited[row*cols+col])
		{
			pathlength++;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathlength, visited)
				||hasPathCore(matrix, rows, cols, row-1, col, str, pathlength, visited)
				||hasPathCore(matrix, rows, cols, row+1, col, str, pathlength, visited)
				||hasPathCore(matrix, rows, cols, row, col + 1, str, pathlength, visited);
			//如果hasPath为假，当前格子不可能处在路径的第pathLength个位置上（所有可能性都检查了）
			if (!hasPath)
			{
				--pathlength;//从当前分支退出，把pathLength减回去，visited清空 
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
			return false;
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		int pathlength = 0;
		for (int row = 0; row < rows; row++) //行
		{
			for (int col = 0; col < cols; col++) //列
			{
				if(hasPathCore(matrix,rows,cols,row,col,str,pathlength,visited))
				{
					return true;
				}
			}
		}
		delete[] visited;
		return false;
	}


};

class Solution1 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (search(board, word, 0, i, j, visited))
					return true;
			}
		}
		return false;
	}
	bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
		if (idx == word.size())
			return true;
		int m = board.size(), n = board[0].size();
		if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx])
			return false;
		visited[i][j] = true;
		bool res = search(board, word, idx + 1, i - 1, j, visited) ||
			search(board, word, idx + 1, i + 1, j, visited) ||
			search(board, word, idx + 1, i, j - 1, visited) ||
			search(board, word, idx + 1, i, j + 1, visited);
		visited[i][j] = false;
		return res;
	}
};
