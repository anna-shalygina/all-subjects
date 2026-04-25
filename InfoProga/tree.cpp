#include <iostream>
#include <vector>
using namespace std;

struct tree 
{
	int inf;           
	tree* left;        
	tree* right;      
	tree* parent;     
};


tree* node(int x) 
{
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}

void insert(tree*& tr, int x) 
{
	tree* n = node(x);
	if (!tr) 
	{
		tr = n;  
	}
	else {
		tree* y = tr;
		while (y) 
		{
			if (n->inf > y->inf) 
			{  
				if (y->right)
				{
					y = y->right;
				}
				else 
				{
					n->parent = y;
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf) 
			{  
				if (y->left) 
				{
					y = y->left;
				}
				else 
				{
					n->parent = y;
					y->left = n;
					break;
				}
			}
			else 
			{
				delete n;
				break;
			}
		}
	}
}

void inorder(tree* tr)
{
	if (tr)
	{
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);
	}
}

tree* find(tree* tr, int x) 
{
	if (!tr || x == tr->inf) 
	{
		return tr;
	}
	if (x < tr->inf) 
	{
		return find(tr->left, x);
	}
	else 
	{
		return find(tr->right, x);
	}
}

int Height(tree* node)
{
	if (!node)
	{
		return -1;
	}
	int leftheight = Height(node->left);
	int rightheight = Height(node->right);
	return 1 + max(leftheight, rightheight);
}

int main()
{
	tree* root = NULL;
	int N, X, target;
	cout << "Input kol of elements:";
	cin >> N;
	cout << "Input elements:";
	for (int i = 0; i < N; i += 1)
	{
		cin >> X;
		insert(root, X);
	}

	inorder(root);
	cout << endl;

	cout << "Input X:";
	cin >> target;

	tree* found = find(root, target);

	if (found)
	{
		int height = Height(found);
		cout << target << endl;
		cout << height << endl;
	}
	else
	{
		cout << target<<"not found";
	}
}

#include <iostream>
#include <vector>
using namespace std;

struct tree
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};


tree* node(int x)
{
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}

void insert(tree*& tr, int x)
{
	tree* n = node(x);
	if (!tr)
	{
		tr = n;
	}
	else {
		tree* y = tr;
		while (y)
		{
			if (n->inf > y->inf)
			{
				if (y->right)
				{
					y = y->right;
				}
				else
				{
					n->parent = y;
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf)
			{
				if (y->left)
				{
					y = y->left;
				}
				else
				{
					n->parent = y;
					y->left = n;
					break;
				}
			}
			else
			{
				delete n;
				break;
			}
		}
	}
}

void inorder(tree* tr)
{
	if (tr)
	{
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);
	}
}

void printnotdeltwo(tree* tr, bool& notdeltwo)
{
	if (!tr)
	{
		return;
	}
	if (tr->left == NULL && tr->right == NULL)
	{
		if (tr->inf % 2 != 0)
		{
			cout << tr->inf << " ";
			notdeltwo = true;
		}
	}
	printnotdeltwo(tr->left, notdeltwo);
	printnotdeltwo(tr->right, notdeltwo);
}

int main()
{
	tree* root = NULL;
	int N, X;
	cout << "Input kol of elements:";
	cin >> N;

	if (N == 0) 
	{
		cout << "Not tree" << endl;
		return 0;
	}

	cout << "Input elements:";
	for (int i = 0; i < N; i += 1)
	{
		cin >> X;
		insert(root, X);
	}

	inorder(root);
	cout << endl;

	bool notdeltwo = false;
	printnotdeltwo(root, notdeltwo);

	if (!notdeltwo)
	{
		cout << "Not leaves which del on two";
	}
	cout << endl;
}


#include <iostream>
#include <vector>
using namespace std;

struct tree
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};


tree* node(int x)
{
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}

void insert(tree*& tr, int x)
{
	tree* n = node(x);
	if (!tr)
	{
		tr = n;
	}
	else {
		tree* y = tr;
		while (y)
		{
			if (n->inf > y->inf)
			{
				if (y->right)
				{
					y = y->right;
				}
				else
				{
					n->parent = y;
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf)
			{
				if (y->left)
				{
					y = y->left;
				}
				else
				{
					n->parent = y;
					y->left = n;
					break;
				}
			}
			else
			{
				delete n;
				break;
			}
		}
	}
}

void inorder(tree* tr)
{
	if (tr)
	{
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);
	}
}

tree* Min(tree* tr)
{
	if (!tr->left)
	{
		return tr;
	}
	return Min(tr->left);
}

tree* find(tree* tr, int x)
{
	if (!tr || x == tr->inf)
	{
		return tr;
	}
	if (x < tr->inf)
	{
		return find(tr->left, x);
	}
	else
	{
		return find(tr->right, x);
	}
}

void Delete(tree*& tr, tree* v)
{
	if (!v)
	{
		return;
	}
	tree* p = v->parent;
	if (!v->left && !v->right)
	{
		if (!p)
		{
			tr = NULL;
		}
		else if (p->left == v)
		{
			p->left = NULL;
		}
		else
		{
			p->right = NULL;
		}
		delete v;
	}
	else if (!v->left && v->right) 
	{
		if (!p) 
		{
			tr = v->right;
			v->right->parent = NULL;
		}
		else if (p->left == v) 
		{
			p->left = v->right;
			v->right->parent = p;
		}
		else 
		{
			p->right = v->right;
			v->right->parent = p;
		}
		delete v;
	}
	else if (v->left && !v->right) 
	{
		if (!p) 
		{
			tr = v->left;
			v->left->parent = NULL;
		}
		else if (p->left == v) 
		{
			p->left = v->left;
			v->left->parent = p;
		}
		else 
		{
			p->right = v->left;
			v->left->parent = p;
		}
		delete v;
	}
	else
	{
		tree* succ = v->right;
		while (succ->left)
		{
			succ = succ->left;
		}
		v->inf = succ->inf;
		Delete(tr, succ);
	}
}

void deletenotdeltwo(tree*& tr)
{
	if (!tr)
	{
		return;
	}

	deletenotdeltwo(tr->left);
	deletenotdeltwo(tr->right);

	if (tr->inf % 2 != 0) 
	{
		Delete(tr, tr);
	}
}


int main()
{
	tree* root = NULL;
	int N, X;
	cout << "Input kol of elements:";
	cin >> N;

	if (N == 0)
	{
		cout << "Not tree" << endl;
		return 0;
	}

	cout << "Input elements:";
	for (int i = 0; i < N; i += 1)
	{
		cin >> X;
		insert(root, X);
	}

	deletenotdeltwo(root);

	inorder(root);
	cout << endl;
}