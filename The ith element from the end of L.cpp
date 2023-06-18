#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node {
    long int info;
    node* next;
};

struct List {
    node* head;
    node* tail;
};

void Init(List& L) {
    L.head = NULL;
    L.tail = NULL;
}

node* getNode(long int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void AddTail(List& L, long int x) {
    node* newele = getNode(x);
    if (L.head == NULL)
    {
        L.head = newele;
        L.tail = newele;
    }
    else
    {
        L.tail->next = newele;
        L.tail = newele;
    }
}

void inputList(List& L, long int n)
{
    while (n > 0)
    {
        long int x; cin >> x;
        AddTail(L, x);
        --n;
    }
}

void outputList(List& L)
{
    if (L.head == nullptr)
        cout << "List is empty";
    else
    {
        node* pTemp = L.head;
        while (pTemp != nullptr)
        {
            cout << pTemp->info << " ";
            pTemp = pTemp->next;
        }
    }
}

node* findElementFromEnd(List& L, int i) {
    int n = 0;
    node* p = L.head;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    if (i > n || i < 1) {
        if (L.head == NULL) {
            cout << "The list is emtpy";
        }
        else cout << "The index is invalid";
        return NULL;
    }
    else {
        p = L.head;
        for (int j = 0; j < n - i; j++) {
            p = p->next;
        }
        return p;
    }
}


int main()
{
    List L;
    Init(L);
    int n; cout << "Enter a number: "; cin >> n;
    cout << "\nEnter a sequence of " << n << " numbers: ";
    inputList(L, n);
    cout << "\nThe created Linked List: ";
    outputList(L);

    int i; cout << "\nEnter a number: "; cin >> i;
    cout << "\nThe element at index " << i << " (from the end of L): ";
    node* p = findElementFromEnd(L, i);
    if (p) cout << p->info;

    return 0;
}
