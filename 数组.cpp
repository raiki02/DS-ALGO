#include< iostream>
using namespace std;

class vector
{
private:
	//int m_val;
	int m_size;
	int* head;
	int m_num;

	void expand(int size) 
	{
		int* q = new int[size];
		memcpy(q, head, 4 * sizeof(int));
		delete head;
		head = q;
		m_size = size;
	}

public:
	vector(int size = 10) : m_size(size),m_num(0)
	{
	 head = new int[size];
	}

	~vector()
	{
		delete[] head;
		head = nullptr;// ??? 
	}

	void push_back(int val)
	{
		if (m_num > m_size)
		{
			expand(2 * m_size);
		}

		head[m_num] = val;
		m_num++;
		
	}

	void pop_back()
	{
		m_num -= 1;
	}

	void show()
	{
		for (int i = 0; i < m_num ; i++)
		{
			cout << head[i] << " ";
			cout << endl;
		}
	}

	void find(int val)
	{
		for (int i = 0; i < m_num; i++)
		{
			if (head[i] == val)
			{
				cout << "元素在第" << i << "号位" << endl;
				return;
			}
		}
		cout << " 未找到该元素！ " << endl;
	}
};

void test01()
{
	vector v;
	v.push_back(12);
	v.push_back(123);
	v.push_back(161);
	v.push_back(15);
	v.show();
	v.find(15);
	v.pop_back();
	v.show();

	v.find(15);
	v.find(14);
}

int main()
{
	test01();

	return 0;
}