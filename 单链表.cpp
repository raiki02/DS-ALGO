//#include<iostream>
//using namespace std;
//#include<time.h>
//#include<stdlib.h>
//
//struct node
//{
//	int m_val;
//	node* m_next;
//
//	node(int val = 0):m_next(NULL) , m_val(val){}
//
//};
//
//class list
//{	
//	node* head = NULL;
//
//public:
//
//	list()
//	{
//		head = new node();
//	}
//
//	~list()
//	{
//		node* p = head;
//		while (p != NULL)
//		{
//			head = head->m_next;
//			delete p;
//			p = head;
//		}
//		head = NULL;
//
//	}
//
//	void push_back(int val)
//	{	
//		node* p = head;
//		while (p->m_next != NULL)
//		{
//			p = p->m_next;
//		}
//
//		node* Node = new node(val);
//		p->m_next = Node;
//	}
//
//	void push_front(int val)
//	{
//		node* Node = new node(val);
//		Node->m_next = head->m_next;
//		head->m_next = Node;
//
//	}
//	
//	void erase(int val)
//	{
//		node* Node = head;
//		node* Node2 = head->m_next;
//
//		while (Node2 != NULL)
//		{
//			if (Node2->m_val == val)
//			{
//				Node->m_next = Node2->m_next;
//				delete Node2;
//				return;
//			}
//			else
//			{
//				Node = Node2;
//				Node2 = Node2->m_next;
//			}
//		}
//	}
//
//	void eraseALl(int val)
//	{
//		node* Node = head;
//		node* Node2 = head->m_next;
//
//		while (Node2 != NULL)
//		{
//			if (Node2->m_val == val)
//			{
//				Node->m_next = Node2->m_next;
//				delete Node2;
//				Node2->m_next = Node;
//			}
//			else
//			{
//				Node = Node2;
//				Node2 = Node2->m_next;
//			}
//		}
//
//	}
//	
//	bool find(int val)
//	{
//		node* p = head->m_next;
//	while (p != NULL)
//	{
//		if (p->m_val == val)
//		{
//			return true;
//		}
//		else
//		{
//			p = p->m_next;
//		}
//	}
//	return false;
//	}
//
//	void show()
//	{
//		node* p = head->m_next;
//		while (p != NULL)
//
//		{
//			cout << p->m_val << " ";
//			p = p->m_next;
//		}
//	}
//
//	friend void reverse(list& l);
//};
//void reverse(list& l)
//{
//	/*node* p = head->m_next;
//	head->m_next = NULL;
//
//	while (p->m_next != NULL)
//	{
//		node* q = p->m_next;
//		p->m_next = head->m_next;
//		head->m_next = p->m_next;
//		p = q;
//
//	}*/
//	node* head = l.head;
//	node* p = head->m_next;
//	if (p == NULL)
//	{
//		return;
//	}
//	head->m_next = NULL;
//	while (p != NULL)
//	{
//		node* q = p->m_next;
//		head->m_next = p;
//		p = q;
//	}
//}
//
//int main()
//{
//	//list l1;
//	//srand(time(0));
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	int v = rand() % 100;
//	//	l1.push_front(v);
//	//	cout << v << " ";
//	//}
//	//cout << endl;
//	//l1.show();
//
//	list l1;
//	l1.push_back(10);
//	l1.push_back(20);
//	l1.push_back(50);
//	l1.push_back(70);
//	l1.push_back(30);
//	l1.show();
//	cout << endl;
//	reverse(l1);
//	l1.show();
//
//	return 0;
//}



//#include <iostream>
//
//// ��������ڵ�ṹ��
//struct ListNode {
//    int data;
//    ListNode* next;
//    ListNode(int x) : data(x), next(NULL) {}
//};
//
//// ��������
//ListNode* createList() {
//    ListNode* head = NULL;
//    ListNode* tail = NULL;
//
//    int num;
//    std::cout << "���������������� -1 ������: ";
//    std::cin >> num;
//
//    while (num != -1) {
//        ListNode* newNode = new ListNode(num);
//        if (head == NULL) {
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//
//        std::cout << "���������������� -1 ������: ";
//        std::cin >> num;
//    }
//
//    return head;
//}
//
//// ��ӡ����
//void printList(ListNode* head) {
//    ListNode* curr = head;
//    while (curr != NULL) {
//        std::cout << curr->data << " ";
//        curr = curr->next;
//    }
//    std::cout << std::endl;
//}
//
//// ��ͷ������ڵ�
//ListNode* insertAtHead(ListNode* head, int val) {
//    ListNode* newNode = new ListNode(val);
//    newNode->next = head;
//    return newNode;
//}
//
//// ��β������ڵ�
//void insertAtTail(ListNode* head, int val) {
//    ListNode* newNode = new ListNode(val);
//    ListNode* curr = head;
//    while (curr->next != NULL) {
//        curr = curr->next;
//    }
//    curr->next = newNode;
//}
//
//// ɾ��ָ��ֵ�Ľڵ�
//ListNode* deleteNode(ListNode* head, int val) {
//    if (head == NULL) {
//        return NULL;
//    }
//
//    ListNode* curr = head;
//    ListNode* prev = NULL;
//
//    while (curr != NULL && curr->data != val) {
//        prev = curr;
//        curr = curr->next;
//    }
//
//    if (curr == NULL) {
//        return head;
//    }
//
//    if (prev == NULL) {
//        head = curr->next;
//    }
//    else {
//        prev->next = curr->next;
//    }
//
//    delete curr;
//    return head;
//}
//
//// �ͷ������ڴ�
//void freeList(ListNode* head) {
//    ListNode* curr = head;
//    ListNode* temp;
//
//    while (curr != NULL) {
//        temp = curr;
//        curr = curr->next;
//        delete temp;
//    }
//}
//
//int main() {
//    ListNode* head = createList();
//
//    std::cout << "ԭʼ����: ";
//    printList(head);
//
//    head = insertAtHead(head, 0);
//    std::cout << "��ͷ������ 0 �������: ";
//    printList(head);
//
//    insertAtTail(head, 10);
//    std::cout << "��β������ 10 �������: ";
//    printList(head);
//
//    head = deleteNode(head, 5);
//    std::cout << "ɾ��ֵΪ 5 �Ľڵ�������: ";
//    printList(head);
//
//    freeList(head);
//
//    return 0;
//}




#include<iostream>
using namespace std;

struct Node
{
	int m_val;
	Node* m_next;

	Node(int val = 0) :m_val(val), m_next(nullptr) {};
};

class List
{
public:
	Node* head;

public:
	List()
	{
		head = new Node();
	}
	~List()
	{

	}

public:
	void push_back(int val)
	{
		Node* p = new Node(val);
		Node* q = head;
		while(q->m_next != nullptr)
		{
			q = q->m_next;
			 }
		q->m_next = p;

	}


	void push_front(int val)
	{
		Node* p = new Node(val);
		Node* q = head->m_next;
		head->m_next = p;
		p->m_next = q;
	}

	void pop_front(){}
	void pop_back() {}


	void erase(int val)
	{
		/*Node* p = head;
		while (p->m_val != val)
		{
			p = p->m_next;
		} 
		delete p;   ���� ����ɾ���ᵼ�½ڵ��ж�*/
	}

	void eraseAll(int val)
	{

	}

	void show()
	{
		Node* p = head;
		while (p->m_next != nullptr)
		{
			p = p->m_next;
			cout << p->m_val << " ";
		}
		cout << endl;
	}


	bool find(int val)
	{

	}

	friend bool getLastkNode(List& l, int k, int& val);
	friend void combine(List& l1, List& l2);
	friend void reverse(List& l);
}; 
//Ԫ������

//ʵ�֣� l{ 1 ,2  , 3, 4, 5}-> {5 , 4, 3, 2, 1}
void reverse(List& l)
{
	Node* head = l.head->m_next;//head ָ��1
	Node* p = head;
	while (p->m_next != nullptr)
	{
		p = p->m_next;
		l.push_front(p->m_val);
	} //{ 1, 2, 3, 4, 5 }->{ 5 , 4, 3, 2, 1, 2, 3, 4, 5} ������ɾ��1��Ľڵ�

	p = head->m_next;//pָ��2 
	head->m_next = nullptr;
	
	while (p->m_next != nullptr)
	{
		head = p;
		p = p->m_next;
		delete head;
	}
	//p = head->m_next; //p = &2
	//
	//while (p->m_next != nullptr)
	//{
	//	head->m_next = nullptr;
	//	head = p;
	//	delete head;
	//	p = p->m_next; p���ſ���??
	//}

}

void test_reverse()
{
	List l;
	int arr[] = { 1 , 42 ,46 ,68 ,23 ,47 ,75 };
		for (int num : arr)
		{
			l.push_back(num);
	}
		l.show();

		reverse(l);
		l.show();
}

//������k���ڵ�
bool getLastkNode(List& l, int k, int& val)//���val��ʲô��
{
	Node* head = l.head;
	Node* p = head;
	Node* pre = head;

	if (k < 1)
		return false;//�ж�

	for (int i = 0; i < k; i++)
	{
		p = p->m_next;
		if (p == nullptr)
			return false;//�ж�
	}
	
	while (p != nullptr)
	{
		p = p->m_next;
		pre = pre->m_next;
	}

	val = pre->m_val;//������ѽڵ�ֵ���ݸ��ⲿ�ı�������Ϊ�����ô���
	return true;
}

//��������ϲ�(����
void combine(List& l1, List& l2)
{
	Node* head1 = l1.head;
	Node* head2 = l2.head;

	Node* p = head1->m_next;
	Node* q = head2->m_next;
	Node* last = head1;

	while (p != NULL && q != NULL)
	{
		if (p->m_val < q->m_val)
		{
			last->m_next = p;
			p = p->m_next;
			last = last->m_next;

		}
		else
		{
			last->m_next = q;
			q = q->m_next;
			last = last->m_next;
		}
	}

	if (q == nullptr)
	{
		last->m_next = p;
	}
	else 
	{	
		last->m_next = q;
	}
}

void test_combine()
{
	List l1;
	List l2;

	int arr1[] = { 25 , 37 , 52 ,78 };
	int arr2[] = { 13 , 23, 40 };

	for (int num1 : arr1)
	{
		l1.push_back(num1);
	}

	for (int num2 : arr2)
	{
		l2.push_back(num2);
	}

	combine(l1, l2);

	l1.show();
	l2.show();
}

//�������ж��Ƿ��л�������ڽڵ�
void checkCycle(List& l)
{
	Node* fast = l.head;
	Node* slow = l.head;

	do
	{
		fast = fast->m_next->m_next;
		slow = slow->m_next;

		if (fast == slow)
		{
			cout << " ��������ڻ��� " << endl;
			Node* p = l.head;
			while (p != slow)
			{
				p = p->m_next;
				slow = slow->m_next;

			}
			cout << " �û������Ϊ�� " << p->m_val << endl;
			break;
		 }
		
		
		

	} while (fast != slow);

}


void test_checkCycle01()
{
	List l;
	int arr[] = { 12 , 56 , 23 ,89, 20 ,89 ,10, 66 ,34 };
	for (int num : arr)
	{
		l.push_back(num);
	}
	Node* p = l.head;
	while (p->m_next != NULL)
	{
		p = p->m_next;
	}
	Node* p1 = l.head;
	for (int i = 0; i < 2; i++)
	{
		p1 = p1->m_next;
	}
	

	p->m_next = p1;

	checkCycle(l);
}

bool checkCycle(Node* head, int& val)
{
	Node* fast = head;
	Node* slow = head;

	while (fast != nullptr && fast->m_next != nullptr)
	{
		fast = fast->m_next->m_next;
		slow = slow->m_next;

		if (fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->m_next;
				slow = slow->m_next;
			}
			val = fast->m_val;
			return true;
		}
		
	}
	return false;//��������Ķ�������
	/*while (fast != slow)
	{
		fast = fast->m_next->m_next;
		slow = slow->m_next;
	}
	fast = head;
	while (fast != slow)
	{
		fast = fast->m_next;
		slow = slow->m_next;
	}
	val = fast->m_val;
	return true;*/
	
}

void checkCycle02()
{
	Node* head;
	Node n1(23), n2(59), n3(19), n4(77), n5(34), n6(31);
	head = &n1;
	n1.m_next = &n2;
	n2.m_next = &n3;
	n3.m_next = &n4;
	n4.m_next = &n5;
	n5.m_next = &n6;
	n6.m_next = &n3;
	
	int val;
	if (checkCycle(head, val))
	{
		cout << " ��������ڻ����������Ϊ��" << val << endl;
	}
	else
	{
		cout << " �޻��� " << endl;
	}
}
//�ж��������Ƿ��ཻ
bool isIntersec(Node* head1 , Node* head2 , int& val)

{
	int num1 = 0, num2 = 0;
	Node* p = head1->m_next;//Ϊʲôָ����һ���ڵ�
	Node* q = head2->m_next;
	while (p != NULL)
	{
		num1++;
		p = p->m_next;
	}
	while (q != NULL)
	{
		num2++;
		q = q->m_next;
	}
	p = head1;
	q = head2;

	if (num1 < num2)//�Ƚ�˭��
	{
		int delta = num1 - num2;
		q = head2;
		while (delta-- > 0)
		{
			q = q->m_next;
		}
	}
	else	{
			int delta = num2 - num1;
			p = head1;
			while (delta-- > 0)
			{
				p = p->m_next;
			}
	}
	while (q != NULL && p != NULL)//�����ģ�
	{	
		if (p == q) // ����д��ʲô��
		{
			val = p->m_val;
			return true;
		}

		q = q->m_next;
		p = p->m_next;
	}
	return false;
}

void test_isSec()
{
	Node head1;
	Node n1(23), n2(55), n3(76), n4(123), n5(90);
	head1.m_next = &n1;
	n1.m_next = &n2; 
	n2.m_next = &n3;
	n3.m_next = &n4;
	n4.m_next = &n5; 

	Node head2;
	Node n6(23);
	head2.m_next = &n6;
	n6.m_next = &n2; // �����������Ƿ��ཻ
	

	int val;
	if (isIntersec(&head1, &head2, val))
	{	
		cout << " �����ཻ���ཻ�ڵ�Ϊ��" << val << endl;
	}
	else
	{
		cout << " �����ཻ�� " << endl;
	}
}

//ɾ��������k���ڵ�
//����ʵ��������k���ڵ㣬����slowҪ����һ��ɾ��ǰ���Ǹ�

//��ת����
//eg: {1 , 2 ,4 ,6, 5, 7, 9} k = 2 ->	{ 7 , 9 , 1 ,2 ,4 ,6 ,5 }
void rotate(List& l, int k)
{
	Node* head = l.head;
	int num = 0;
	Node* p = head;
	while (p->m_next != nullptr)
	{
		num++;
		p = p->m_next;
	}
	p = head;
	Node* q = head;
	if (num > k)
	{
		for (int i = 0; i < k; i++)
		{
			q = q->m_next;
		}
		while (q->m_next != nullptr)
		{
			p = p->m_next;
			q = q->m_next;
		}
		q->m_next = head->m_next;
		head->m_next = p->m_next;//��Ҫ�ſ�ָ�룡��
		p->m_next = nullptr;
	}
	else
	{
		k = k % num;
		for (int i = 0; i < k; i++)
		{
			q = q->m_next;
		}
		while (q->m_next != nullptr)
		{
			p = p->m_next;
			q = q->m_next;
		}
		q->m_next = head->m_next;
		head->m_next = p->m_next;
		p->m_next = nullptr;

	}
}


void test_rotate()
{
	int arr1[] = { 1 ,2 ,3 ,4 ,5 , 6 ,7 ,8 ,9 };
	int arr2[] = { 2 , 4 , 6 ,8 };
	List l1;
	List l2;

	for (int num1 : arr1)
	{
		l1.push_back(num1);
	}
	for (int num2 : arr2)
	{
		l2.push_back(num2);
	}

	rotate(l1, 4);
	l1.show();
	cout << " --- " << endl;
	rotate(l2, 7);
	l2.show();

}
int main()
{
	test_combine();
	test_checkCycle01();
	checkCycle02();
	test_isSec();
	test_reverse();
	test_rotate();
	return 0;
}