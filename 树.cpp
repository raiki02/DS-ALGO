#include<iostream>
using namespace std;
#include<functional>
#include<time.h>
#include<random>
//template<class T>
//class BSTree
//{
//private:
//	struct Node
//	{
//		int m_val;
//		Node* m_left;
//		Node* m_right;
//
//		Node(int val = 0) :m_val(val), m_left(nullptr), m_right(nullptr)
//		{
//			new Node(val);
//		}
//		~Node() {
//
//		}
//	};
//		
//	Node* root;
//
//	BSTree()
//	{
//		root = new Node();
//	}
//public:
//	void insert(int val)
//	{
//
//	}
//};

template<typename T, typename Compare = less<T>>
class BSTree
{
private:
	struct Node
	{
		int mval;
		Node* left;
		Node* right;

		Node(int val = 0) :mval(val), left(nullptr), right(nullptr) {}
	};

	Node* root;

	void fprint(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->mval << " ";
			fprint(node->left);
			fprint(node->right);
		}
	}

	void mprint(Node* node)
	{
		if (node != nullptr)
		{
			mprint(node->left);
			cout << node->mval<< " ";
			mprint(node->right);
		}
	}

	void bprint(Node* node)
	{
		if (node != nullptr)
		{
			bprint(node->left);
			bprint(node->right);
			cout << node->mval << " ";
		}
	}
		void levelprint(Node * node, int i)
		{
			if (node == nullptr)
			{
				return;
				}
			if (i == 0)
			{
				cout << node->mval << " ";
				return;
			}

			levelprint(node->left, i - 1);
			levelprint(node->right, i - 1);
		}

		int height(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}

			int left = height(node->left);
			int right = height(node->right);

			return left > right ? left + 1 : right + 1;
		}

		int number(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			int left = number(node->left);
			int right = number(node->right);
			return left + right + 1;
		}


	

public:
	
	BSTree() :root(nullptr) {}
	~BSTree() {}

	void n_insert(int& val)
	{
		Compare Compare;
		if (root == NULL)
		{
			//root->mval = val;
			root = new Node(val);
			return;
		}
		Node* cur = root;
		Node* parent = NULL;
		while (cur != NULL)
		{
			////if (cur->mval > val)
			//if(!Compare(cur->mval , val))//greater
			//{
			//	parent = cur;
			//	cur = cur->left;
			//}
			////else if (cur->mval < val)
			//else if (Compare(cur->mval, val) ) //less
			//{
			//	parent = cur;
			//	cur = cur->right;
			//}
			//else
			//{
			//	return;
			//}
			if (cur->mval == val)
			{
				return;
			}
			else if (Compare(cur->mval, val))
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				parent = cur;
				cur = cur->left;
			}
		}

		if (parent->mval > val)
		{
			parent->left = new Node(val);
		}
		else
		{
			parent->right = new Node(val);
		}

	}

	void n_remove(const T& val)
	{
		if (root == nullptr)
		{
			return;
		}

		Compare comp;
		Node* parent = nullptr;
		Node* cur = root;

		while (cur != NULL)
		{
			//if (!comp(cur->mval, val))
			//{
			//	parent = cur;
			//	cur = cur->left;
			//}
			//else if (comp(cur->mval, val))
			//{
			//	parent = vur;
			//	cur = cur->right;
			//}
			//else
			//{
			//	//return;
			//	break;//val found
			//}

			if (cur->mval == val)
			{
				break;//found
			}
			else if (comp(cur->mval, val))
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				parent = cur;
				cur = cur->left;
			}

			if (cur == nullptr)
			{
				return; // val not found
			}

			if (cur->left != nullptr && cur->right != nullptr)
			{
				parent = cur;
				Node* pre = cur->left;
				while (pre->right != nullptr)
				{	
					parent = pre;
					pre = pre->right;
				}
				cur->mval = pre->mval;
				cur = pre;
			}

			Node* child = cur->left;
			if (child == nullptr)
			{
				child = cur->right;
			}

			if (parent == nullptr)
			{
				root = child;
			}
			else
			{
				if (parent->left == cur)
				{
					parent->left = child;
				}
				else
				{
					parent->right = child;
				}
			}

			delete cur;
		}
	}

	bool n_find(int val)
	{
		if (root == nullptr)
		{
			cout << "bst is empty!" << endl;
			return false;
		}

		Node* cur = root;
		while (cur != nullptr)
		{
			if (cur->mval == val) 
			{
				cout << " val : " << val << " found. " << endl;
				return true;
			}
			else if (cur->mval > val)
			{
				cur = cur->left;
			}
			else if (cur->mval < val)
			{
				cur = cur->right;
			}
		}

		cout << " val : " << val << " not found. " << endl;
		return false;
	}

	//void fprint(Node* p) //vlr
	//{	
	//	if (root == nullptr)
	//	{ 
	//		cout << " bst is empty! " << endl;
	//		return;
	//	}
	//	
	//	cout << p->mval << " ";
	//	while (p->left != nullptr)
	//	{
	//		fprint(p->left);
	//	}
	//		
	//		fprint(p->right)
	//	}
	//void fprint(Node* p)
	//{
	//	if (root == nullptr)
	//	{
	//		cout << " bst is empty! " << endl;
	//		return;
	//	}
	//	if (p == nullptr)
	//	{
	//		cout << " p already nullptr! " << endl;
	//		return;
	//	}
	//	while (p != nullptr)
	//	{
	//		cout << p->mval << " ";
	//		fprint(p->left);
	//	}
	//	while (p != nullptr)
	//	{
	//		cout << p->mval << " ";
	//		fprint(p->right);
	//	}
	//}
	void fprint()
	{
		cout << "fprint: ";
		fprint(root);
		cout << endl;
	}

	void mprint() //lvr
	{
		cout << "mprint: ";
		mprint(root);
		cout << endl;
	}

	void bprint() //lrv
	{
		cout << "bprint: ";
		bprint(root);
		cout << endl;
	}

	void levelprint()
	{
		cout << "levelprint: ";
		int h = height(root);
		for (int i = 0; i < h; i++)
		{
			levelprint(root, i);
		}
		cout << endl;
	}

	int height()
	{
		return height(root);
	}

	int number()
	{
		return number(root);
	}
};


int main()
{	
	//srand(time(NULL));
	int a[10] = {};
	//for (int i = 0; i < 10; i++)
	//{
	//	a[i] = rand() % 100;
	//}
	//int len = sizeof(a) / sizeof(a[0]);
	//cout << "a[] = ";
	//for (int v : a)
	//{
	//	
	//	cout << v << " ";
	//	
	//}
	//cout << endl;
	//BSTree<int> bst;
	//for (int i = 0; i < len; i++)
	//{
	//	bst.n_insert(a[i]);
	//}


	//int arr[] = { 12,21,7,9,1,95,17,8,13,70 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	

	srand(time(NULL));
	int test[10] = {};
	for (int i = 0; i < 10; i++)
	{
		test[i] = rand() % 100;
	}


	cout << "test[10] = ";
	for (int v : test)
	{
		cout << v << " ";
	}
	cout << endl;

	BSTree<int> bst;
	for (int i = 0; i < 10; i++)
	{
		bst.n_insert(test[i]);
	}
	
	bst.fprint();
	bst.mprint();
	bst.bprint();
	//bst.fprint(bst.root);

	bst.levelprint();
	cout << bst.height() << endl;
	cout << bst.number() << endl; 

	if (bst.n_find(12))
	{
		cout << "12 found" << endl;

	}
	else
	{
		cout << " 12 not found " << endl;
	}


	return 0;
}