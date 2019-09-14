#include <string>
#include <algorithm>
#include <stack>
using namespace std;

/*����˼·��
1.����һ������start��¼��Ч�����Ӵ�����ʼ�±꣬max��ʾ���Ч�����Ӵ����ȣ���ʼֵ��Ϊ0
2.�������ַ����е������ַ�
	2.1����ǰ�ַ�s[index]Ϊ������'('������ǰ�ַ��±�index��ջ���±��Ժ��������ô�����������һ�ַ�
	2.2����ǰ�ַ�s[index]Ϊ������')'���жϵ�ǰջ�Ƿ�Ϊ��
		2.2.1��ջΪ�գ���start = index + 1��������һ�ַ�����ǰ�ַ��������±겻��ջ��
		2.2.2��ջ��Ϊ�գ����ջ�����ڽ���������ջ�����ջԪ�ض�Ӧ���ַ�һ��Ϊ�����ţ����뵱ǰ�ַ���������ԣ����ж�ջ�Ƿ�Ϊ��
			2.2.2.1��ջΪ�գ���max = max(max, index-start+1)
			2.2.2.2��ջ��Ϊ�գ���max = max(max, index-ջ��Ԫ��ֵ)
*/
class Solution 
{
public:
	int longestValidParentheses(string s) 
	{
		int start = 0, res = 0;
		int len = s.length();
		if (len == 0) return 0;
		stack<int> stmp;
		for (int i = 0; i < len; i++)
		{
			if ('(' == s.at(i))
			{
				stmp.push(i);
				continue;
			}
			else
			{
				if (stmp.empty())
				{
					start = i + 1;
					continue;
				}
				else
				{
					stmp.pop();
					if (stmp.empty())
						res = max(res, i - start + 1);
					else
						res = max(res, i - stmp.top());
				}
			}
		}
		return res;
	}
};

/*
 * ��������dp[s.length()]����ʾ�ӵ�ǰ�ַ���ʼ�����ַ�����β�����Ч�����Ӵ�����
 *����ǰ�ַ���Ϊ��Ч�����Ӵ��ĵ�һ���ַ���
 *
 */
/* ����˼·�����ַ�����β��ǰ������������dp[]
 * ��ǰ�ַ��±�Ϊindex������ǰ�ַ�Ϊ������'('���ж�index+1+d[index+1]λ�õ��ַ��Ƿ�Ϊ������')'��
 * ��Ϊ�����ţ���d[index] = d[index+1]+2�������ж�index+1+d[index+1]+1λ�õ�Ԫ���Ƿ���ڣ������ڣ�
 * ��d[index] += d[index+1+d[index+1]+1]���������������Ч�����Ӵ�ֱ�����ڵ������
 */
class Solution2
{
public:
	int longestValidParentheses(string s)
	{
		int len = s.length();
		if (0 == len) return 0;
		int res = 0;
		int *dp = new int[len];
		for (int i = 0;i < len;i++)
			dp[i] = 0;
		for (int index=len-2;index>=0;index--)
		{
			int cur = index + 1 + dp[index + 1];
			if ('(' == s.at(index) && cur < len&&')' == s.at(cur))
			{
				dp[index] = dp[index + 1] + 2;
				if (cur + 1 < len)//�������()()����
					dp[index] += dp[cur + 1];
			}
			res = max(res, dp[index]);
		}
		return res;
	}
};