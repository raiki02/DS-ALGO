//////#include<iostream>
//////#include<stack>
//////using namespace std;
//////
//////void test01()
//////{
//////	stack<int> s1;
//////	s1.push(1);
//////	s1.push(2); 
//////	s1.push(6);
//////	s1.push(3);
//////	s1.push(5);
//////	s1.push(7);
//////	cout << s1.top() << endl;
//////}	
//////
//////int main()
//////{
//////	test01();
//////	return 0;
//////
//////
//////class stack
//////{
//////	int m_val;
//////	stack* m_next;
//////	stack* m_pre;
//////	stack* head;
//////public:
//////	stack()
//////	{
//////		stack* p = new stack[10];
//////		stack* &head = p;
//////	}
//////
//////
//////	~stack()
//////	{	
//////		delete[] head;
//////	}
//////
//////	void push(int val)
//////	{
//////		stack* p = head->m_next;
//////	}
//////};
//
////1.顺序栈
//#include<iostream>
//using namespace std;
//
//class stack
//{
//private:
//	int mtop;
//	int mcap;
//	int* mpstack;
//
//
//private:
//	void expand(int size)
//	{
//		int* p = new int[size];
//		memcpy(p, mpstack, mtop * sizeof(int));
//		//mpstack = NULL; 只是改变指向，原先被占用的内存并未被释放
//		delete[] mpstack;
//		mpstack = p;
//	}
//public:
//	stack(int size = 10):mcap(size), mtop(0)
//	{
//		mpstack = new int[size];
//	}
//
//	~stack() 
//	{
//		delete[] mpstack;
//		mpstack = NULL;//!!
//	} 
//
//public:
//
//	void push(int val)
//	{
//		if (mtop == mcap)
//		{
//			expand(mcap * 2);
//		}
//		mpstack[mtop] = val;
//		mtop++;
//	}
//
//	void pop()
//	{
//		if (mtop == 0)
//			throw "stack is empty !";
//		mtop--;
//	}
//
//	bool empty() 
//	{
//		return mtop == 0;
//	}
//
//	int size() const
//	{
//		//return mtop * sizeof(int); 这是全部的字节数，应打印元素个数
//		return mtop;
//	}
//
//	int top() const 
//	{
//		if (mtop == 0)
//			throw "stack is empty !";
//		return mpstack[mtop - 1];
//	}
//};
//////2.链式栈
//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	int m_val;
//	Node* m_next;
//	Node(int val = 0) : m_val(val), m_next(nullptr) {}
//};
//
//class stack
//{
//public:
//	Node* head;
//	stack()
//	{
//		head = new Node();
//	}
//
//	~stack()
//	{
//		Node* p = head;
//		//Node* q;
//		while (p != nullptr)
//		{
//			head = head->m_next;
//			delete p;
//			p = head;
//
//		/*	q = p;
//			delete q;
//			q = nullptr;
//			p = p->m_next;*/ //相对更安全
//		}
//	}
//
//public:
//
//	void push(int val)
//	{
//		/*Node* p = head;
//		while (p != nullptr)
//		{
//			p = p->m_next;
//		}
//
//		val = p->m_val;*/ // 这里不对，要创建新节点，并且这个p也不指向最后一个节点
//
//		Node* p = new Node(val);
//		Node* q = head;
//		while (q->m_next != nullptr)
//		{
//			q = q->m_next;
//
//		}
//		q->m_next = p;
//	}
//
//	void pop() //栈是先进后出，上者实现尾插，这里实现尾删
//	{
//		/*Node* p = head->m_next;
//		Node* q = p->m_next;
//		delete p;
//		p = nullptr;
//		head->m_next = q;*///这是头删。。
//
//		Node* q = head;
//		Node* p = head->m_next;
//		while (p->m_next != nullptr)
//		{
//			q = q->m_next;
//			p = p->m_next;
//		}
//		delete p;
//		q->m_next = nullptr;
//	}
//	//要么实现头插头删，要么实现尾插尾删。
//	void show()
//	{
//		Node* p = head;
//		while (p->m_next != nullptr)
//		{
//			p = p->m_next;
//			cout << p->m_val << " ";
//			
//		}
//	}
//
//
//	bool empty()
//	{
//		//...
//	}
//
//	int top()
//	{
//		//...
//	}
//};
//
//void test_pushAndPop()
//{
//	stack s1;
//	s1.push(12);
//	s1.push(2512);
//	s1.push(57);
//	s1.push(34);
//	s1.push(79);
//	s1.push(246);
//	s1.show();
//	cout << endl;
//	s1.pop();
//	s1.show();
//	cout << endl;
//	s1.pop();
//	s1.show();
//	cout << endl;
//	s1.pop();
//	s1.show();
//	cout << endl;
//	s1.pop();
//	s1.show();
//	cout << endl;
//
//}
//
//int main()
//{
//	test_pushAndPop();
//
//	return 0;
//}