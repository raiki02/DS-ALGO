//#include<iostream>
//using namespace std;
//
////���ַǵݹ�
//int binary(int arr[], int size, int val)
//{
//	int first = 0;
//	int last = 0; ??? 
//
//	while (first <= last)
//	{
//		int mid = (first + last) / 2;
//
//		if (arr[mid] == val)
//		{
//			return mid;
//		}
//		else if (arr[mid] > val)
//			{
//			last = mid - 1;
//		}
//		else
//		{
//			first = mid + 1;
//		}
//	}
//	return -1;
//}
//
////���ֵݹ�
//
//int binary(int arr[], int i, int j, int val)
//{
//	int mid = (i + j) / 2;
//
//	if (i > j)
//	{
//		return -1;
//	} // ��������
//
//	
//		if (arr[mid] == val)
//		{
//			return mid;
//		}
//		else
//			if (arr[mid] > val)
//			{
//				return binary(arr, i, mid - 1, val);
//			}
//			else
//				if (arr[mid] < val)
//				{
//					return binary(arr, mid + 1, j, val);
//				}
//	
//	
//}