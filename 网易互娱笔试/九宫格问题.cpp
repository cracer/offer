#include <iostream>
using namespace std;

int 



int main()
{
	int num;//九宫格个数
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int  rows, columns;
		cin >> rows >> columns;
		int **arr = new int*[rows];//rows行3列
		for (int j = 0; j < rows; j++)
		{
			arr[j] = new int[columns];
			for (int k = 0; k < columns; k++)
				cin >> arr[j][k];
		}
	}
	system("pause");
	return 0;
}