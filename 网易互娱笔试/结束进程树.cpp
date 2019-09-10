/*
 * ����������
ʱ�����ƣ�C / C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C / C++���� 65536KB���������� 589824KB
��Ŀ������
����n�����̣���Щ������������������
��1��ÿ��������Ψһ��PID������PIDΪ����ID
��2��ÿ���������ֻ��һ�������̣��������ж���ӽ��̣���PPID��ʾ������ID
��3����һ������û�и����̣�����PPIDΪ0
��4��PID��PPID�����޷�������
�����������ĺ����ǵ�����һ������ʱ�����������ӽ���Ҳ�ᱻ�����������ӽ��̵��ӽ��̡�
���ڸ�����СΪn�����������б�A��B��1 <= n <= 100�����б�A��ʾ���̵�PID�б��б�B
��ʾ�б�A��Ӧ�ĸ����̵��б���PPID�б�
���ٸ���һ��PID�������������PID�Ľ�����ʱ�ܹ������Ľ���������
����
3 1 5 21 10
0 3 3 1 5
5
���
2
��������
3 1 5 21 10
0 3 3 1 5
3
�������
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
