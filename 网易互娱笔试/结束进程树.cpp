/*
 * 结束进程树
时间限制：C / C++语言 1000MS；其他语言 3000MS
内存限制：C / C++语言 65536KB；其他语言 589824KB
题目描述：
给定n个进程，这些进程满足以下条件：
（1）每个进程有唯一的PID，其中PID为进程ID
（2）每个进程最多只有一个父进程，但可能有多个子进程，用PPID表示父进程ID
（3）若一个进程没有父进程，则其PPID为0
（4）PID、PPID都是无符号整数
结束进程树的含义是当结束一个进程时，它的所有子进程也会被结束，包括子进程的子进程。
现在给定大小为n的两组输入列表A和B（1 <= n <= 100），列表A表示进程的PID列表，列表B
表示列表A对应的父进程的列表，即PPID列表。
若再给定一个PID，请输出结束该PID的进程树时总共结束的进程数量。
输入
3 1 5 21 10
0 3 3 1 5
5
输出
2
样例输入
3 1 5 21 10
0 3 3 1 5
3
样例输出
5
 */

#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


int CountKillProcess1(vector<int> &son, vector<int> &parent,int killNum)
{
	vector<int> v;
	queue<int> q{ {killNum} };
	unordered_map<int, vector<int> > u;
	for (int i = 0; i < (int)parent.size(); i++)
	{
		u[parent[i]].push_back(son[i]);
	}
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		v.push_back(tmp);
		for(auto i : u[tmp])
		{
			q.push(i);
		}
	}
	return v.size();

}

void helper(int kill, unordered_map<int, vector<int>>& m, vector<int>& res) 
{
	res.push_back(kill);
	for (int p : m[kill]) 
	{
		helper(p, m, res);
	}
}

int CountKillProcess(vector<int> &son, vector<int> &parent, int killNum)
{
	vector<int> v;
	
	unordered_map<int, vector<int> > u;
	for (int i = 0; i < (int)parent.size(); i++)
	{
		u[parent[i]].push_back(son[i]);
	}
	helper(killNum, u, v);
	
	return v.size();
}




int main()
{
	vector<int> vSon{3,1,5,21,10};
	// int stmp, ptmp;
	// do 
	// {
	// 	cin >> stmp;
	// 	vSon.push_back(stmp);
	// } while (getchar() != '\n');
	vector<int> vParent{0,3,3,1,5};
	// do 
	// {
	// 	cin >> ptmp;
	// 	vParent.push_back(ptmp);
	// } while (getchar() != '\n');
	int num = 3;
	// cin >> num;

	cout << CountKillProcess(vSon, vParent, num) << endl;
	system("pause");
	return 0;
}
