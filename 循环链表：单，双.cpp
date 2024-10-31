#include<iostream>
using namespace std;


struct Node
{
	int m_val;
	Node* m_next;
	Node(int val = 0) :m_val(val), m_next(nullptr) {}
};

class singleList
{
public:
	


	singleList()
	{
		head = new Node();
		tail = head;
		head->m_next = head;

		//tail = head->m_next;此时tail指向空，也没有达成闭环。。
	}
	~singleList()
	{
		Node* p = head->m_next;
		while (p != head)
		{
			head->m_next = p->m_next;
			delete p;
			p = head->m_next;
		}
		delete head;//还要删除头节点。。。
	}

	void show()
	{
		Node* p = head->m_next;
		while (p != head)
		{
			cout << p->m_val << " ";
			p = p->m_next;
		}
	}

	void push_back(int val)
	{
	/*	Node* p = new Node(val);
		tail->m_next = p;
		p->m_next = head->m_next;*/
		
		Node* p = new Node(val);
		p->m_next = tail->m_next;
		tail->m_next = p;
		tail = p;
	}

	void push_front(int val)
	{
		Node* p = new Node(val);
		p->m_next = head->m_next;
		head->m_next = p;
		if (p->m_next = head)
		{
			tail = p;
		}
	}

	void erase(int val)
	{
		Node* p = head->m_next;
		Node* q = head;
		while (p != head)//是p还是p->m_next????
		{
			if (p->m_val == val)
			{
				q->m_next = p->m_next;
				delete p;
				if (q->m_next == head)
				{
					tail = q;
				}

				return;
			}
			else
			{
				q = p;
				p = p->m_next;
			}
		}
	}

	bool find(int val)
	{
		Node* p = head->m_next;
		while (p != head)
		{
			if (p->m_val == val)
			{
				return true;
			}
			p = p->m_next;
			
		}
		return false;
	}



public:
	Node* tail;
	Node* head;
};

//约瑟夫环
void Joseph (Node* head, int k, int m)
{
	Node* p = head;
	Node* q = head;

	while (q->m_next != head)
	{
		q = q->m_next;//如果每次第一个报数的话不用这个会导致第一次报数后for跳出
	}
	for (int i = 1; i < k; i++)
	{
		q = p;
		p = p->m_next;
	}

	for (;;)
	{
		for (int j = 1; j < m; j++)
		{
			q = p;
			p = p->m_next;
		}
		cout << p->m_val << " ";

		if (q == p)
		{
			delete p;
			break;
		}

		q->m_next = p->m_next;
		delete p;
		p = q->m_next;

		
	}
}


void test_Joseph()
{
	Node* n1 = new Node(12);
	Node* n2 = new Node(134);
	Node* n3 = new Node(5341);
	Node* n4 = new Node(13734);
	Node* n5 = new Node(451);
	Node* n6 = new Node(172);
	Node* n7 = new Node(841);
	Node* n8 = new Node(1134); 
	Node* n9 = new Node(1246);
	Node* n10 = new Node(157);
	Node* n11 = new Node(261);
	

	n1->m_next = n2;
	n2->m_next = n3;
	n3->m_next = n4;
	n4->m_next = n5;
	n5->m_next = n6;
	n6->m_next = n7;
	n7->m_next = n8;
	n8->m_next = n9;
	n9->m_next = n10;
	n10->m_next = n11;
	n11->m_next = n1;
	
	
	Joseph(n1,2,3);
}
void test_push_back()
{
	singleList l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.show();

	singleList l2;
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(5);
	l2.push_back(6);
	l2.show();
}


int main()
{
	//test_push_back();
	test_Joseph();

	return 0;

}
