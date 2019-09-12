/*
 *给你一个01字符串，定义答案=该串中最长的连续1的长度，现在你有至多K次机会，
 *每次机会可以将串中的某个0改成1，现在问最大的可能答案
 *
 *输入描述:
输入第一行两个整数N,K，表示字符串长度和机会次数
第二行输入N个整数，表示该字符串的元素
( 1 <= N <= 300000
, 0 <= K <= N )
输出描述:
输出一行表示答案
示例1
输入
10 2
1 0 0 1 0 1 0 1 0 1
输出
5
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LongestString(int m,int n, string str)//m, n，表示字符串长度和机会次数
{
	int left = 0, right = 0;
	int res = 0;
	while(right < m)
	{
		if(n==0)
		{
			res = max(res, right - left + 1);
		}
		if (str[right] == '0')
			n -= 1;
		else
			right++;

	}
	return 0;
}

int main()
{
	int m, n;
	cin >> m >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	
	cout << LongestString(m, n, str);
	return 0;
}

/*
int n, m, tmp;
int main() {
	scanf("%d %d", &n, &m);
	int sum[n + 1];
	sum[0] = 0;
	for (int i = 1;i <= n;++i) {
		scanf("%d", &tmp);
		sum[i] = sum[i - 1] + tmp;
		//cout<<sum[i]<<endl;
	}
	int ans = m;
	int i = 0, j;
	while (i < n) {
		if (sum[i + 1] - sum[i] > 0) {
			int j = ans + i;
			while (j <= n) {
				if (j - i - sum[j] + sum[i] > m) break;
				++j;
			}
			if (j != n) --j;
			//cout<<j<<' '<<i<<endl;
			ans = max(ans, j - i);
		}
		++i;
	}
	cout << ans << endl;
}
*/