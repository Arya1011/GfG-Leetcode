#include <bits/stdc++.h>
using namespace std;

typedef multiset<int>::iterator It;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *insertInBST(node *root, int d)
{
	// Base Case
	if (root == NULL)
	{
		return new node(d);
	}
	// Recursive Case(Insert in Subtree and Update the pointers)
	if (d <= root->data)
	{
		root->left = insertInBST(root->left, d);
	}
	else
	{
		root->right = insertInBST(root->right, d);
	}
	return root;
}

node *build()
{
	int d;
	cin >> d;
	node *root = NULL;
	while (d != -1)
	{
		root = insertInBST(root, d);
		cin >> d;
	}
	return root;
}
void inorder(node *root)
{
	if (root == NULL)
	{
		return;
	}
	// Left
	inorder(root->left);
	cout << root->data << ",";
	// Right
	inorder(root->right);
}

void levelTraversal(node *root)
{
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node *f = q.front();
		if (f == NULL)
		{
			cout << endl;
			q.pop();
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << f->data << " ";
			q.pop();
			if (f->left)
			{
				q.push(f->left);
			}
			if (f->right)
			{
				q.push(f->right);
			}
		}
	}
	return;
}

bool search(node *root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->data == data)
	{
		return true;
	}
	// Recursive Case
	if (data <= root->data)
	{
		return search(root->left, data);
	}
	else
	{
		return search(root->right, data);
	}
}

node *deleteFromBST(node *root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	// Searching for node in LST
	if (data < root->data)
	{
		root->left = deleteFromBST(root->left, data);
		return root;
	}
	// We have found the node
	else if (root->data == data)
	{
		// 0 children
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		// 1 children
		if (root->left != NULL && root->right == NULL)
		{
			node *temp = root->left;
			delete root;
			return temp;
		}
		if (root->right != NULL && root->left == NULL)
		{
			node *temp = root->right;
			delete root;
			return temp;
		}
		// 2 children(here we will replace such a node with its successor in inorder traversal)
		node *replace = root->right;
		// Finding the minimum node in the RST which will be the immediate successor of the deleted node in inorder
		while (replace->left != NULL)
		{
			replace = replace->left;
		}
		// Making the successor as the root
		root->data = replace->data;
		// Since root is now changed we need to also delete the element which is now the new root from the RST
		root->right = deleteFromBST(root->right, replace->data);
		return root;
	}
	// Searching for node in RST
	else
	{
		root->right = deleteFromBST(root->right, data);
		return root;
	}
}

bool isBST(node *root, int minv = INT_MIN, int maxv = INT_MAX)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data <= maxv && root->data >= minv && isBST(root->left, minv, root->data) && isBST(root->right, root->data, maxv))
	{
		return true;
	}
	return false;
}

class LinkedList
{
public:
	node *head;
	node *tail;
};

LinkedList flatten(node *root)
{
	LinkedList l;
	// This case is when our tree is completely empty

	if (root == NULL)
	{
		l.head = l.tail = NULL;
		return l;
	}
	// Leaf node
	if (root->right == NULL && root->left == NULL)
	{
		l.head = l.tail = root;
		return l;
	}
	// If left node is not NULL
	if (root->left != NULL && root->right == NULL)
	{
		LinkedList LeftLL = flatten(root->left);
		LeftLL.tail->right = root;

		l.head = LeftLL.head;
		l.tail = root;
		return l;
	}

	// If right node is not NULL
	if (root->right != NULL && root->left == NULL)
	{
		LinkedList RightLL = flatten(root->right);
		root->right = RightLL.head;

		l.head = root;
		l.tail = RightLL.tail;
		return l;
	}

	// Neither left nor right is NULL
	LinkedList LeftLL = flatten(root->left);
	LinkedList RightLL = flatten(root->right);
	LeftLL.tail = root;
	root->right = RightLL.head;
	l.head = LeftLL.head;
	l.tail = RightLL.tail;
	return l;
}

class person_compare
{
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		return p2.second > p1.second;
	}
};

// largest BST in a tree
class details
{
public:
	bool bst;
	int size = 0;
	int _max;
	int _min;
};

// O(n) approach
details helper(Node *root)
{
	details d;

	// for a null node there is nor right bound and left bound
	if (root == NULL)
	{
		d.bst = true;
		d.size = 0;
		d._max = INT_MIN;
		d._min = INT_MAX;
		return d;
	}

	details l = helper(root->left);
	details r = helper(root->right);

	// not a bst
	if (!l.bst || !r.bst || root->data <= l._max || root->data >= r._min)
	{
		d.bst = false;
		d.size = max(l.size, r.size);
		return d;
	}

	// current rooted subtree is bst
	d.bst = true;
	d.size = l.size + r.size + 1;
	d._min = root->left == NULL ? root->data : l._min;
	d._max = root->right == NULL ? root->data : r._max;
	return d;
}

int largestBst(Node *root)
{

	details d = helper(root);
	return d.size;
	// Your code here
}

int main()
{
	node *root = build();

	// inorder(root);
	// cout<<endl;
	// cout<<endl;
	// cout<<endl;

	levelTraversal(root);
	// cout<<endl;
	// cout<<endl;
	// cout<<endl;

	// cout<<isBST(root)<<endl;

	LinkedList l = flatten(root);
	node *temp = l.head;
	while (temp != NULL)
	{
		cout << temp->data << "--->";
		temp = temp->right; // Here right is serving as next in case of linked list
	}
	// cout<<search(root,6);

	// node*newroot=deleteFromBST(root,7);
	// levelTraversal(newroot);

	/*
	//Set STL(uses BST in the background)
	int arr[]={1,2,1,3,2,1,4,5,4,5,2};
	int n=sizeof(arr)/sizeof(int);
	set<int> s;
	for(int i=0;i<n;i++){
	s.insert(arr[i]);
	}
	for(auto it=s.begin();it!=s.end();it++){
	cout<<*it<<" ";
	}
	cout<<endl;
	cout<<endl;
	s.erase(1);
	auto it=s.find(4);
	s.erase(it);
	for(auto it=s.begin();it!=s.end();it++){
	cout<<*it<<" ";
	}
	*/

	/*
	//Multiset STL(stores multiple elements that have same values)
	//Stored in specific sorted manner according to internal comparison object
	//values once inserted cant be modified
	int arr[]={10,20,30,30,30,30,30,20,10,10};
	multiset<int> m(arr,arr+6);
	int n=sizeof(arr)/sizeof(int);
	m.erase(20);
	m.insert(80);
	for(int x:m){
	cout<<x<<" ";
	}
	cout<<endl;
	cout<<m.count(10);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	//Get all elements which are equal to 30
	pair<It,It> range=m.equal_range(30); //gives back 2 iterators one pointing to first occurence of the element and the second pointing to one ahead of last occurence of an element

	for(auto it=range.first;it!=range.second;it++){
	 cout<<*it<<"--";
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;



	//Multiset of custom data types
	Pair<string:name,int:money>
	pair<string,int>p1=make_pair("A",400);
	pair<string,int>p2=make_pair("B",200);
	pair<string,int>p3=make_pair("C",300);


	multiset<pair<string,int>,person_compare> m;
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);


	//By default the pairs will be printed in lexicographic ordering
	for(auto x:m){
	cout<<x.first<<"-"<<x.second<<endl;
	}

	}
	*/
  
