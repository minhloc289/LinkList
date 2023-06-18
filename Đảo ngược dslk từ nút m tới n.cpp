#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
};

Node* makenode(int x) {
	Node* newNode = new Node;
	newNode->info = x;
	newNode->next = NULL;
	return newNode;
}

void pushFront(Node*& head, int x) {
	Node* p = makenode(x);
	p->next = head;
	head = p;
}

void pushBack(Node*& head, int x) {
	Node* temp = head;
	Node* newNode = makenode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void print(Node* head) {
	while (head != NULL) {
		cout << head->info << " ";
		head = head->next;
	}
}

Node *reserve(Node* head) {
	Node* pre = NULL;
	Node* current = head;
	Node* next = NULL;
	while (current) {
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	return pre;
}

Node* reserveBetween(Node* head, int m, int n) {
	if (m == n) {
		return head;
	}
	Node* start = NULL, * end = NULL;
	Node* s_pre = NULL, *e_next = NULL;
	Node* current = head;
	int i = 1;
	while (current != NULL && i <= n) {
		if (i < m) {
			s_pre = current;
		}
		if (i == m) {
			start = current;
		}
		if (i == n) {
			end = current;
			e_next = current->next;
		}
		current = current->next;
		i++;
	}
	end->next = NULL;
	end = reserve(start);
	if (s_pre != NULL) {
		s_pre->next = end;
	}
	else {
		head = end;
	}
	start->next = e_next;
	return head;
}

int main() {
	Node* head = NULL;
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pushBack(head, a[i]);
	}
	int h, k;
	cin >> h >> k;
	head = reserveBetween(head, h, k);
	print(head);
	return 0;
}