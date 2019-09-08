#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;


int BinTree(int **arr, int rows)
{
	set<int> s;
	for (int i = 0; i < rows; i++)
	{
		s.insert(arr[i][1]);
		s.insert(arr[i][2]);
	}
	vector<int> v;//寻找头结点
	for (int j = 0; j < rows; j++)
	{
		if (s.count(j) == 0)
		{
			v.push_back(j);
			break;
		}
	}
	
	while (!v.empty())
	{
		vector<int> vtmp(v);
		v.clear();
		int up = 0, down = 0;
		for (int i = 0; i < (int)vtmp.size(); i++)
		{
			up += arr[vtmp[i]][0];//上层节点值总和
		}
		for (int i = 0; i < (int)vtmp.size();i++)
		{
			if (arr[vtmp[i]][1] != -1)
				v.push_back(arr[vtmp[i]][1]);
			if (arr[vtmp[i]][2] != -1)
				v.push_back(arr[vtmp[i]][2]);
		}
		for (int i = 0; i < (int)v.size(); i++)
			down += arr[v[i]][0];//下层节点值总和
		if (!v.empty() && up >= down)
			return 0;
	}
	return 1;
}

int main3()
{
	int num;
	cin >> num;
	int* res = new int[num];
	for (int index = 0; index < num;index++)
		res[index] = 0;
	for (int i = 0; i < num; i++)
	{
		int rows;
		cin >> rows;
		int **arr = new int*[rows];//rows行3列
		for (int j = 0; j < rows; j++)
		{
			arr[j] = new int[3];
			for (int k = 0; k < 3; k++)
				cin >> arr[j][k];
		}	
		int tmp = BinTree(arr, rows);
		if (tmp == 1)
			res[i] = 1;
	}
	for (int i = 0; i < num; i++)
	{
		if (res[i] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	
	system("pause");
	return 0;
}
