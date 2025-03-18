#include<iostream>
using namespace std;
class BST;
class TreeNode
{
	friend class BST;
	int data; // The value in the node
	TreeNode *left; // Pointer to left child node
	TreeNode *right; // Pointer to right child node

};
class BST
{
	TreeNode* root;
		int max_count=0;
	int min_count=0;
	int lenght_=0;
	void inOrder(TreeNode* t)
	{
		if (t != 0)
		{
			inOrder(t->left);
			cout << t->data << " ";
			inOrder(t->right);
		}
	}

	void insert(TreeNode*& t,int val)
	{

		if (t == 0)
		{
			t = new TreeNode;
			t->data = val;
			t->left = nullptr;
			t->right = nullptr;
		}
		else if (val < t->data)
		{

			insert(t->left, val);
		}
		else if (val > t->data)
		{
			insert(t->right, val);
		}
	}
	int minimum(TreeNode* t)
	{

		while (t && t->left != 0)
		{
		     min_count++;
			t = t->left;

		}
		return t->data;
	}
	int maximum(TreeNode* t)
	{

		while (t && t->right != 0)
		{
		    max_count++;

			t = t->right;
		}
		return t->data;
	}

public:
    void height()
    {

        int x=maximum();
        int y=minimum();

        int max=max_count;
        int min= min_count;
        if(max>min)
            cout<<"Height of tree is  ="<<max;
        else
            cout<<"Height of tree is  ="<<min;
    }
	BST()
	{
		root = nullptr;
	}
	~BST()
	{}
	void inOrder()
	{
		inOrder(root);
	}

	void insert(int val)
	{

		insert(root, val);
	}
	bool search(int val)
	{
		TreeNode* t=root;
		while (t != 0)
		{
			if (t->data == val)
			{
				cout << val<<" exists...!\n";
				return true;
			}
			else if (val < t->data)
				t = t->left;
			else
			t = t->right;
		}
		cout << val << " does not exist...!\n";
		return false;
	}
	int minimum()
	{
		return minimum(root);
	}
	int maximum()
	{
		return maximum(root);
	}
	void length(TreeNode* t)
	{

		if (t != 0)
		{
             lenght_++;
			length(t->left);
			length(t->right);
		}
	}
	void length()
	{
	    length(root);
	    cout<<lenght_;

	}
	bool remove(int val)
	{

		TreeNode* curr = root, *parent = 0;
		while (curr != 0 && curr->data != val)
		{
			parent = curr;
			if (val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else
		{
			if (curr->left != 0 && curr->right != 0)
			{
				TreeNode *l = curr->left, *pl = curr;
				while (l->right != 0)
				{
					pl = l;
					l = l->right;
				}
				curr->data = l->data;
				curr = l;
				parent = pl;
			}
			TreeNode* child;
			if (curr->left != 0)
			{
				child = curr->left;
			}
			else
			{
				child = curr->right;
			}
			if (curr == root)
			{
				root = child;
			}
			else
			{
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
		}
	}
};
int main()
{
	BST b1;
	b1.insert(5);
	b1.insert(7);
	b1.insert(4);
	b1.insert(3);
	b1.insert(2);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();
	cout << endl;
	b1.search(10);
	b1.remove(5);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();

cout<<endl;
b1.height();
cout<<endl<<"length of tree = ";
b1.length();
	return 0;
}

