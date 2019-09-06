using namespace std;

class Solution
{
public:
	void replaceSpace(char* str,int length)
	{
		int i = length - 1, j, cnt = 0;
		while (i>0)
		{
			if(str[i]==' ')
			{
				for(j=length;j>=i;j--)
				{
					str[j + 2] = str[j];
				}
				str[i] = '%';
				str[i+1] = '2';
				str[i+2] = '0';
				length += 2;
			}
			i--;
		}
	}
};