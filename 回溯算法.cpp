#include<iostream>
#include<limits>
#include<cmath>
#include<vector>
using namespace std;

#if 0
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
#endif


/*
证书选择问题：给定一个整数数组，从中选择多个数，使得和为k，和剩下的整数和的差最小
*/
#if 0
int arr[] = { 12,6,7,11,16,3,9};
const int length = sizeof(arr) / sizeof(arr[0]);
int x[length] = { 0 };
int bestx[length] = { 0 };
int sum = 0;
int r = 0;
unsigned int Min = std::numeric_limits<unsigned int>::max();
int cnt = 0;

void func(int i)
{
	if (i == length)
	{
		cnt++;
		int result = abs(sum - r);
		if (result < Min)
		{
			Min = result;
			for (int j = 0; j < length; ++j)
			{
				bestx[j] = x[j];
			}
		}
	}
	else
	{
		r -= arr[i];
		sum += arr[i];
		x[i] = 1;
		func(i + 1);
		r += arr[i];
		sum -= arr[i];
		x[i] = 0;
		func(i + 1);
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
	{
		r += arr[i];
	}
	func(0);
	for (int i = 0; i < length; ++i)
	{
		if (bestx[i] == 1)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	cout << "Min = " << Min << endl;
	cout << "cnt = " << cnt << endl;
	return 0;
}
#endif


/*
给定2n个整数，从里面选出n个整数，使得这n个整数的和与另外n个整数的和的差最小
*/

#if 0
int arr[] = { 12,6,7,11,16,3,9,8 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;
vector<int> bestx;
int sum = 0;
int r = 0;
int Left = length;
unsigned int Min = std::numeric_limits<unsigned int>::max();
int cnt = 0;

void func(int i)
{
	if (i == length)
	{
		if (x.size() != length/2)
		{
			return;
		}
		cnt++;

		int result = abs(sum - r);
		if (result < Min)
		{
			Min = result;
			bestx = x;
		}
	}
	else
	{
		Left--;//剩下的数的个数
		if (x.size() < length / 2)//剩下的数的个数大于要选的数的个数
		{
			r -= arr[i];
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			r += arr[i];
			sum -= arr[i];
			x.pop_back();
		}
		
		if (x.size() + Left >= length / 2)//剩下的数的个数加上已经选的数的个数大于等于要选的数的个数
		{
			func(i + 1);
		}
		Left++;//回溯
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
	{
		r += arr[i];
	}
	func(0);
	for (int i = 0; i < length; ++i)
	{
		if (find(bestx.begin(), bestx.end(), arr[i]) != bestx.end())
		{
			cout << arr[i] << " ";
		}
		
	}
	cout << endl;
	cout << "Min = " << Min << endl;
	cout << "cnt = " << cnt << endl;
	return 0;
}
#endif


/*
请挑选出一组数字，让他们的和等于给定的数字，存在解打印，不存在打印不存在
*/
#if 0
int arr[] = { 4,8,12,16,7,9,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;
int sum = 0;
int k = 18;
void func(int i)
{
	if (i == length)
	{
		if (sum != k)
		{
			return;
		}
		for (int v : x)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	else
	{
		
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			sum -= arr[i];
			x.pop_back();
		
		func(i + 1);
	}
}

int main()
{
	func(0);
	return 0;
}
#endif



/*
请挑选出一组数字，让他们的和等于给定的数字，存在解打印，不存在打印不存在
*/
#if 0
int arr[] = { 4,8,12,16,7,9,3,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;
int sum = 0;
int number = 18;
int cnt = 0;

void func(int i) {
	if (i == length) {
		cnt++;
		if (sum != number)
		{
			return;
		}
		
	
		for (int v : x) {
			cout << v << " ";
		}
		cout << endl;
	}
	else 
	   {
		for (int k = i; k < length; k++) {
			
			
			if (sum + arr[k] <= number)
				{
				sum += arr[k];
				x.push_back(arr[k]);
				func(k + 1);
				
				sum -= arr[k];
				x.pop_back();
				}
		
		}
		
	}


}

int main()
{
	func(0);
	cout << "cnt = " << cnt << endl;
	return 0;
}
#endif


/*
0-1背包问题:有n个物品，每个物品的重量为w[i]，价值为v[i]，背包的容量为C，求解将哪些物品装入背包可使价值最大
*/
#if 0
int w[] = { 2,2,6,5,4,10,1,9 };
int v[] = { 6,3,5,4,6,999,888,233 };
const int length = sizeof(w) / sizeof(w[0]);//物品的个数
int x[length] = { 0 };//x[i] = 1表示第i个物品放入背包，x[i] = 0表示第i个物品不放入背包
int bestx[length] = { 0 };//最优解//bestx[i] = 1表示第i个物品放入背包，bestx[i] = 0表示第i个物品不放入背包
int C = 10;//背包的容量
int cw = 0;//当前背包的重量
int cv = 0;//当前背包的价值
int bestv = 0;//最优解的价值
int cnt = 0;//计数
int r = 0;//剩下的物品的价值

void func(int i)
{
	if (i == length)
	{
		cnt++;
		if (cv > bestv)//如果当前背包的价值大于最优解的价值
		{
			bestv = cv;
			for (int j = 0; j < length; ++j)
			{
				bestx[j] = x[j];
			}
		}
	}
	else
	{
		r -= v[i];
		//左剪枝
		if (cw + w[i] <= C)//剪枝//如果当前背包的重量加上当前物品的重量小于等于背包的容量
		{
			cw += w[i];
			cv += v[i];
			x[i] = 1;
			func(i + 1);
			cw -= w[i];
			cv -= v[i];
			x[i] = 0;
		}
		//右剪枝
		//if (cv + (C - cw) * v[i] > bestv)
		//	//如果当前背包的价值加上剩下的物品的价值大于最优解的价值
		//	// //剩下的物品的价值为剩下的物品的重量乘以剩下的物品的价值
		//	// //剩下的物品的重量为背包的容量减去当前背包的重量
		//	//(C-cw) * v[i]就是一个估算的剩余物品的最大价值。
		//	//C-cw表示剩下的物品的重量
		//	//v[i]是第i个物品的价值
		//{
		//	func(i + 1);
		//}
		if (r + cv > bestv)
		{
			func(i + 1);
		}
		r += v[i];
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
	{
		r += v[i];
	}
	func(0);
	for (int i = 0; i < length; ++i)
	{
		if (bestx[i] == 1)
		{
			cout << w[i] << " ";
		}
	}
	cout << endl;
	cout << "bestv = " << bestv << endl;
	cout << "cnt = " << cnt << endl;
	return 0;
}
#endif


/*
解空间-排列树 O(n!)
*/
#if 0
int arr[] = { 1,2,3,4};
const int length = sizeof(arr) / sizeof(arr[0]);
void func(int i)
{
	if (i == length)
	{
		for (int j = 0; j < length; ++j)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = i; j < length; ++j)
			
		{
			swap(arr[i], arr[j]);
			func(i + 1);
			swap(arr[i], arr[j]);
		}
	}
}
int main()
{
	func(0);
	return 0;
}
#endif

/*
*八皇后问题:在8*8的国际象棋上摆放8个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上
*/
#if 0
int arr[8] = { 0 };
int cnt = 0;
void func(int i)
{
	if (i == 8)
	{
		cnt++;
		for (int j = 0; j < 8; ++j)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = 0; j < 8; ++j)
		{
			arr[i] = j;
			int k = 0;
			for (k = 0; k < i; ++k)
			{
				if (arr[i] == arr[k] || abs(arr[i] - arr[k]) == i - k)
				{
					break;
				}
			}
			if (k == i)
			{
				func(i + 1);
			}
		}
	}
}

int main()
{
	func(0);
	cout << "cnt = " << cnt << endl;
	return 0;
}
#endif


#if 0
int ar[] = { 1,2,3,4,5,6,7,8 };
int length = sizeof(ar) / sizeof(ar[0]);
int cnt = 0;

bool judge(int ar[], int i) {//判断第i个皇后是否和前面的皇后冲突//如果冲突返回false，否则返回true
	for (int j = 0; j < i; j++) {
		if ((abs(ar[i] - ar[j]) == abs(i - j)) || i == j || ar[j] == ar[i]) {
			return false;
		}
	}
	return true;
}

void swap(int ar[], int i, int j) {
	int temp = ar[i];
	ar[i] = ar[j];
	ar[j] = temp;
}

void func(int ar[], int i, int length)
{
	if (i == length)
	{	
		cnt++;
		for (int j = 0; j < length; j++) {
			cout << ar[j] << " ";
		}
		cout << endl;
	}
	else {
		for (int k = i; k < length; k++) {
			swap(ar,i, k);
			if (judge(ar, i))
			{
				func(ar, i + 1, length);

			}
			swap(ar,i, k);
		}
	}
}



int main()
{
	func(ar, 0, length);
	cout << "cnt = " << cnt << endl;
	return 0;
}
#endif

/*
满足leetcode的全排列问题
*/
int arr[] = { 1,2,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;
bool visited[length] = { false };
void func(int i) {
	if (i == length)
	{
		for (int j = 0; j < length; j++)
		{
			cout << x[j] << " ";
		}
		cout << endl;
	}
	else {
		for (int j = 0; j < length; j++) {
			if (!visited[j]) {
				visited[j] = true;
				x.push_back(arr[j]);
				func(i + 1);
				visited[j] = false;
				x.pop_back();
			}


		}

	}

}

int main()
{
	func(0);
	return 0;
}