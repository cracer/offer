/*
 * 寻祖问宗
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
姓氏是人的符号标志，是家族血脉的传承；族谱是家族血脉传承的文字记载。
同姓的两个中国人，根据族谱或许能够查出上面几代内是同一个祖先。查一下族谱，
也许当代某位同姓名人就是你的远房亲戚，惊喜不惊喜，意外不意外！！！
输入
二元查找树（1.若左子树不空，左子树值都小于父节点；2.如右子树不空，右子树值都大于父节点；
3.左、右子树都是二元查找树；4. 没有键值相等的节点）上任意两个节点的值，请找出它们最近的公共祖先。
输入三行行，第一行为树层级，第二行为数节点（其中-1表示为空节点），第三行为需要查找祖先的两个数。
在例图中（虚线框没有真实节点，为了输入方便对应位置输-1）查找12和20的最近公共祖先
输入为：
4
9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
12 20
输出
输出给出两个数在树上的最近公共祖先数值，如果没有公共祖先，输出-1；如果其中一个节点是另一个节点的祖先，
输出这个祖先点（如例图中找15、20最近公共祖先，输出15）；如果输入无效，输出-1。
样例输入
4
9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
12 20
样例输出
15
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

 int lowestCommonAncestor(int* tmp,int node1,int node2, int len)
 {	
 	int index = 0;
 	int MIN = min(node1, node2);
 	int MAX = max(node1, node2);
 	while (index < len)
 	{
		if (tmp[index] == MIN || tmp[index] == MAX)
			return tmp[index];
		else if (tmp[index] > MIN&&tmp[index] < MAX)
			return tmp[index];
		if (tmp[index] > MAX)
			index = index * 2 + 1;
		else
			index = index * 2 + 2;
 	}
	return -1;
 }

int main()
{
	 // int num;
	 // cin >> num;
	 // int len = pow(2, num) - 1;
	 // int *arr = new int[len];
	 // for (int i = 0; i < len; i++)
	 // {
	 // 	cin >> arr[i];
	 // }
	 // int node1, node2;
	 // cin >> node1 >> node2;
	 int arr[15] = { 9,6,15,2,-1,12,25,-1,-1,-1,-1,-1,-1,20,37 };

	 cout << lowestCommonAncestor(arr, 37, 20, 15);
	system("pause");
	return 0;
}