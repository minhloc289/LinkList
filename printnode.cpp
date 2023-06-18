#include <iostream>
using namespace std;

typedef struct node {
	int info;
	node* left, * right;
};

typedef node* Tree;

Tree getNode(int x) {
	node* p = new node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void insertTree(Tree& T, int x) {
	if (T != NULL) {
		if (x < T->info) {
			insertTree(T->left, x);
		}
		else if (x > T->info) {
			insertTree(T->right, x);
		}
	}
	else T = getNode(x);
}

void inputTree(Tree& T) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insertTree(T, x);
	}
}

void NLR(Tree T) {
	if (T) {
		cout << T->info << " ";
		NLR(T->left);
		NLR(T->right);
	}
}

void LRN(Tree T) {
	if (T) {
		LRN(T->left);
		LRN(T->right);
		cout << T->info << " ";
	}
}

void LNR(Tree T) {
	if (T) {
		LNR(T->left);
		cout << T->info << " ";
		LNR(T->right);
	}
}

void listLeafs(Tree T) {
	if (T) {
		if (T->left == NULL && T->right == NULL) {
			cout << T->info << " ";
		}
		else {
			listLeafs(T->left);
			listLeafs(T->right);
		}
	}
}

void listInternalNodes(Tree T, int i) {
	if (T) {
		if (i != 0) {
			if (T->left || T->right) {
				cout << T->info << " ";
			}
		}
		listInternalNodes(T->left, 1);
		listInternalNodes(T->right, 1);
	}
}

void listNodesWithOneChild(Tree T) {
	if (T) {
		if ((!T->left && T->right) || (T->left && !T->right)) {
			cout << T->info << " ";
		}
		listNodesWithOneChild(T->left);
		listNodesWithOneChild(T->right);
	}
}

void listNodesWithTwoChildren(Tree T) {
	if (T) {
		if (T->left && T->right) {
			cout << T->info << " ";
		}
		listNodesWithTwoChildren(T->left);
		listNodesWithTwoChildren(T->right);
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "\nNLR: "; NLR(T);
	cout << "\nLRN: "; LRN(T);
	cout << "\nLNR: "; LNR(T);

	cout << "\nLeaf nodes: "; listLeafs(T);
	cout << "\nInternal nodes: "; listInternalNodes(T, 0);
	cout << "\nNodes with one child: "; listNodesWithOneChild(T);
	cout << "\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
