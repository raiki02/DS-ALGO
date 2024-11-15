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
֤��ѡ�����⣺����һ���������飬����ѡ��������ʹ�ú�Ϊk����ʣ�µ������͵Ĳ���С
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
����2n��������������ѡ��n��������ʹ����n�������ĺ�������n�������ĺ͵Ĳ���С
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
		Left--;//ʣ�µ����ĸ���
		if (x.size() < length / 2)//ʣ�µ����ĸ�������Ҫѡ�����ĸ���
		{
			r -= arr[i];
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			r += arr[i];
			sum -= arr[i];
			x.pop_back();
		}
		
		if (x.size() + Left >= length / 2)//ʣ�µ����ĸ��������Ѿ�ѡ�����ĸ������ڵ���Ҫѡ�����ĸ���
		{
			func(i + 1);
		}
		Left++;//����
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
����ѡ��һ�����֣������ǵĺ͵��ڸ��������֣����ڽ��ӡ�������ڴ�ӡ������
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
����ѡ��һ�����֣������ǵĺ͵��ڸ��������֣����ڽ��ӡ�������ڴ�ӡ������
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
0-1��������:��n����Ʒ��ÿ����Ʒ������Ϊw[i]����ֵΪv[i]������������ΪC����⽫��Щ��Ʒװ�뱳����ʹ��ֵ���
*/
#if 0
int w[] = { 2,2,6,5,4,10,1,9 };
int v[] = { 6,3,5,4,6,999,888,233 };
const int length = sizeof(w) / sizeof(w[0]);//��Ʒ�ĸ���
int x[length] = { 0 };//x[i] = 1��ʾ��i����Ʒ���뱳����x[i] = 0��ʾ��i����Ʒ�����뱳��
int bestx[length] = { 0 };//���Ž�//bestx[i] = 1��ʾ��i����Ʒ���뱳����bestx[i] = 0��ʾ��i����Ʒ�����뱳��
int C = 10;//����������
int cw = 0;//��ǰ����������
int cv = 0;//��ǰ�����ļ�ֵ
int bestv = 0;//���Ž�ļ�ֵ
int cnt = 0;//����
int r = 0;//ʣ�µ���Ʒ�ļ�ֵ

void func(int i)
{
	if (i == length)
	{
		cnt++;
		if (cv > bestv)//�����ǰ�����ļ�ֵ�������Ž�ļ�ֵ
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
		//���֦
		if (cw + w[i] <= C)//��֦//�����ǰ�������������ϵ�ǰ��Ʒ������С�ڵ��ڱ���������
		{
			cw += w[i];
			cv += v[i];
			x[i] = 1;
			func(i + 1);
			cw -= w[i];
			cv -= v[i];
			x[i] = 0;
		}
		//�Ҽ�֦
		//if (cv + (C - cw) * v[i] > bestv)
		//	//�����ǰ�����ļ�ֵ����ʣ�µ���Ʒ�ļ�ֵ�������Ž�ļ�ֵ
		//	// //ʣ�µ���Ʒ�ļ�ֵΪʣ�µ���Ʒ����������ʣ�µ���Ʒ�ļ�ֵ
		//	// //ʣ�µ���Ʒ������Ϊ������������ȥ��ǰ����������
		//	//(C-cw) * v[i]����һ�������ʣ����Ʒ������ֵ��
		//	//C-cw��ʾʣ�µ���Ʒ������
		//	//v[i]�ǵ�i����Ʒ�ļ�ֵ
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
��ռ�-������ O(n!)
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
*�˻ʺ�����:��8*8�Ĺ��������ϰڷ�8���ʺ�ʹ�䲻�ܻ��๥���������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб����
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

bool judge(int ar[], int i) {//�жϵ�i���ʺ��Ƿ��ǰ��Ļʺ��ͻ//�����ͻ����false�����򷵻�true
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
����leetcode��ȫ��������
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