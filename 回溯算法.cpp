#include<iostream>
using namespace std;

void func(int arr[], int i, int length)
{
	static int num = 0;
	cout << "num = " << ++num << " " << endl;

	if (i == length)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	else
	{
		func(arr, i + 1, length);
		func(arr,  i + 1 , length);
	}
}

int main()
{
	
	int arr[] = { 1 , 2 ,3 };
	func(arr, 0, 3);
	return 0;
}