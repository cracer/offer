#include <iostream>
using namespace std;

int Jiugongge(int rows,int columns,int** arr)
{
	int a = 1, b = 1;//a行b列 左上角
	int c = rows, d = columns;//c行d列 右上角
	return 0;
}




int main4()
{
	int num;//九宫格个数
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int  rows, columns;
		cin >> rows >> columns;
		int **arr = new int*[rows];
		for (int j = 1; j <= rows; j++)
		{
			arr[j] = new int[columns];
			for (int k = 1; k <= columns; k++)
				cin >> arr[j][k];
		}


	}
	system("pause");
	return 0;
}