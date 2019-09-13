#include <cstdlib>
#include <iostream>
using namespace std;

void createHeap(int arr[],int sPoint,int Len) //创建大根堆
{
	while ((2*sPoint+1)<Len)
	{
		int mPoint = 2 * sPoint + 1;
		if ((2*sPoint+2)<Len)
		{
			if(arr[2 * sPoint + 1]< arr[2 * sPoint + 2])
			{
				mPoint = 2 * sPoint + 2;
			}
		}
		if (arr[sPoint] < arr[mPoint])
		{
			int tmp = arr[sPoint];
			arr[sPoint] = arr[mPoint];
			arr[mPoint] = tmp;
			sPoint = mPoint;
		}
		else
			break;
	}
	return;
}

void heapSort(int arr[], int Len) //堆排序
{
	int i = 0;

	for (i = (Len/2-1); i >= 0; i--)
	{
		createHeap(arr, i, Len);
	}

	for (i = Len - 1; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		createHeap(arr, 0, i);
	}
	return;
}

int main1231321(void)
{
	int arr[] = { 5,4,7,3,9,1,6,8,2 };
	cout << "Before Sorted:\n";
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	heapSort(arr, 9);
	cout << "After Sorted:\n";
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}