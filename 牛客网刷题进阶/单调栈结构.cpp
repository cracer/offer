#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
/*
 * 题目描述：
 * 给定一个可能含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。
 * 返回所有位置相应的信息。
 *
 * 输入描述：
 * 第一行输入一个数字 n，表示数组 arr 的长度。以下一行输入 n 个数字，表示数组的值
 * 7
 * 3 4 1 5 6 2 7
 *
 * 输出描述：
 * 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
 *
 * -1  2
 *  0  2
 * -1 -1
 *  2  5
 *  3  5
 *  2 -1
 *  5 -1
 *
 * 备注：
 * 1≤n≤1000000，−1000000≤arr_i≤1000000
 */

int main() {
	int n;
	// scanf("%d", &n);
	cin >> n;
	vector<int> datas(n);
	vector<int> Lres(n, -1);
	vector<int> Rres(n, -1);
	stack<int> arrdeq;
	for (int i = 0; i < n; i++) 
	{
		// scanf("%d", &datas[i]);
		cin >> datas[i];
		while (!arrdeq.empty() && datas[arrdeq.top()] >= datas[i])
		{
			arrdeq.pop();
		}
		if (!arrdeq.empty()) 
		{
			Lres[i] = arrdeq.top();
		}
		arrdeq.push(i);
	}
	stack<int> arrdeq2;
	for (int i = n - 1; i >= 0; i--) 
	{
		while (!arrdeq2.empty() && datas[arrdeq2.top()] >= datas[i]) 
		{
			arrdeq2.pop();
		}
		if (!arrdeq2.empty())
		{
			Rres[i] = arrdeq2.top();
		}
		arrdeq2.push(i);
	}


	for (int i = 0; i < n; i++) 
	{
		 printf("%d %d\n", Lres[i], Rres[i]);
	}
	system("pause");
	return 0;
}