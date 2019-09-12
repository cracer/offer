/*
 *����һ��01�ַ����������=�ô����������1�ĳ��ȣ�������������K�λ��ᣬ
 *ÿ�λ�����Խ����е�ĳ��0�ĳ�1�����������Ŀ��ܴ�
 *
 *��������:
�����һ����������N,K����ʾ�ַ������Ⱥͻ������
�ڶ�������N����������ʾ���ַ�����Ԫ��
( 1 <= N <= 300000
, 0 <= K <= N )
�������:
���һ�б�ʾ��
ʾ��1
����
10 2
1 0 0 1 0 1 0 1 0 1
���
5
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LongestString(int m,int n, string str)//m, n����ʾ�ַ������Ⱥͻ������
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