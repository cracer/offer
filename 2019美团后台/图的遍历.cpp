#include <iostream>
using namespace std;
int arr[100005];
/*���·�� = 2*(n-1) - maxDepth (n-1)Ϊ�ߵ�����*/
int main()
{
	int n;
	cin >> n;


	for(int i = 1;i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[b] = arr[a] + 1;
	}

	int maxDepth = 0;
	for (int i = 1; i <= n; i++)
	{
		maxDepth = arr[i] > maxDepth ? arr[i] : maxDepth;
	}
	cout << "maxDepth��" << maxDepth << endl;
	cout << 2 * (n - 1) - maxDepth << endl;
	system("pause");
	return 0;
}