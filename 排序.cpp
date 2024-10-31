#include<iostream>
using namespace std;
#include<ctime>
#include<cstdlib>
int arr[11] = { 0 };
//升序
void test01()
{//冒泡


	for (int i = 0; i < 11; i++)
	{
		bool flag = false;
		for (int j = 0; j < 11 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag)
		{
			return;
		}
	}
	//如果某一趟没有数据交换，那么就可以直接返回，因为已经排好了
	for (int i = 0; i < 11; i++)
	{
		cout << arr[i] << " ";
	}
}

//void test02()
//{//选择
//	int min = arr[0];
//	for (int i = 0; i < 11; i++)
//	{
//		for (int j = 0; j < 11; j++)
//		{
//			if (arr[j] < min)
//			{
//				min = arr[j];
//				
//			}
//			
//		}
//		arr[i] = min;
//	}
//}



void test02(int arr[] , int size)
{	//选择

	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];
		int k = i;
		for (int j =i + 1/*这里要是k后面一个元素*/; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				k = j;
			}

		}
		if (k != i)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	
}

//插入
//void test03(int arr[] ,int size)
//{
//	for (int i = 0; i < size; i++)
//	{	
//		int k = i + 1;
//		int min = arr[i + 1];
//		for (int j = i + 1 ; j >= 0; j--)
//		{
//			if (arr[j] > min)
//			{
//				int temp = arr[j];
//				arr[j] = min;
//				min = temp;
//			}
//		}
//	}
//}
//void test03(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		
//		int min = arr[i + 1];
//
//		for (int j = i + 1 ; j > 0 ; j--)
//		{
//			if (min < arr[j])
//			{
//				int temp = min;
//				min = arr[j];
//				arr[j] = temp;
//				continue;
//			}
//		}
//	}
//}
//一个向前走，一个向后走. 前要比较 ，它小就换，前的原点留一个

//void insertsort(int arr[], int size)
//{
//	for (int i = 0; i < size; i++) 
//	{
//		
//		for (int j = i + 1 ; j >= 0; j--)
//		{
//			
//		}
//	}
//}
//插入
void test03(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int val = arr[i];
		int j = i -1 ;
		for (; j >= 0; j--)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];

			
		}
		arr[j + 1] = val;
	}
}

//快速
int partation(int arr[], int l, int r)
{
	int val = arr[l];

	while (r > l)
	{
		while (r > l && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		while (r > l && arr[l] < val)
		{
			l++;

		}
		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}

	}
	arr[l] = val;
	return l; 
}

void quicksort(int arr[] , int begin , int end)
{
	if (begin >= end)
	{
		return;
	}

	/*if (end - begin < 100)
	{
		test03(arr , begin , end);
		return;
	}  数据趋于有序用插入更好*/
	int pos = partation(arr, begin, end);

	quicksort(arr, begin, pos - 1);
	quicksort(arr, pos + 1, end);


}

void quicksort(int arr[], int size)
{
	quicksort(arr, 0, size - 1);
}

//归并
/*	1.将数组分散，每个子数组只有一个元素
	2.合并子数组，此时进行排序
*/

//void test05(int arr[], int begin, int end)
//{
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int temp[n];
//	while (begin < end)
//	{
//		int mid = (begin + end) / 2;
//		test05(arr, begin, mid);
//		test05(arr, mid + 1, end);
//	}
//}
void merge(int arr[], int l, int m, int r)
{
	int* p = new int[r - l + 1];
	int idx = 0;
	int i = l;
	int j = m + 1;
	/*while (l < r)
	{
		while (l < m)
		{

		}

		while (m < r)
		{

		}
	}*/

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}

	}
		while (i <= m)
		{
			p[idx++] = arr[i++];
		}

		while (j <= r)
		{
			p[idx++] = arr[j++];
		}

		for (i = l, j = 0; i <= r; i++, j++)
		{
			arr[i] = p[j];
		}

		delete[] p;

}

void Mergesort(int arr[], int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;

	Mergesort(arr, begin, mid);
	Mergesort(arr, mid + 1, end);

	merge(arr, begin, mid, end);

}

void Mergesort(int arr[], int size)
{
	Mergesort(arr,0,size - 1);
}

//自实现归并
void mergeSort(int arr[], int begin , int end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;

	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, begin, end);
}

void merge(int arr[], int left, int right)
{
	int* p = new int[right - left + 1];
	int i = left;
	int j = right;
	int val = p[i];
	while (i > j)
	{
		while(arr[j] > val && i > j)
		{
			j--;
		}
		
		while (arr[i] < val && i > j)
		{
			i++;
		}
	}

	delete[] p;
}

void mergeSort(int arr[], int size)
{
	mergeSort(arr, 0, size - 1);
}



int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int myarr[10];
	for (int i = 0; i < 10; i++)
	{
		myarr[i] = rand() % 100 ;
	}

	for (int v : myarr)
	{
		cout << v << " ";
	}
	cout << endl;

	Mergesort(myarr, 0 , 9);

	for (int v : myarr)
	{
		cout << v << " ";
	}


	return 0;
}