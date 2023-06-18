
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

void concate(List& L1, List& L2) {
    if (L1.head == NULL) {
        L1.head = L2.head;
        L1.tail = L2.tail;
    }
    else if (L2.head != NULL) {
        L1.tail->next = L2.head;
        L1.tail = L2.tail;
    }
}

int main()
{
    List L1, L2;
    Init(L1); Init(L2);

    int n; cin >> n;
    inputList(L1, n);
    cout << "Created 1st List: " << endl;
    outputList(L1);
    cout << endl;

    cin >> n;
    inputList(L2, n);
    cout << "Created 2nd List: " << endl;
    outputList(L2);
    cout << endl;

    concate(L1, L2); // Noi L2 vao L1
    cout << "Updated L1: " << endl;
    outputList(L1);

    return 0;
}
