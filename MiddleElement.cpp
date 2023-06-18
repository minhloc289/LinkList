
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node {
    long int info;
    node* next;
};

struct List {
    node* pHead;
    node* pTail;
};

node* getNode(long int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void AddTail(List& L, long int x) {
    node* newele = getNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = newele;
        L.pTail = newele;
    }
    else
    {
        L.pTail->next = newele;
        L.pTail = newele;
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
    if (L.pHead == nullptr)
        cout << "List is empty";
    else
    {
        node* pTemp = L.pHead;
        while (pTemp != nullptr)
        {
            cout << pTemp->info << " ";
            pTemp = pTemp->next;
        }
    }
}

node* findMiddle(List L) {
    if (L.pHead == NULL) {
        return NULL;
    }

    node* p = L.pHead;
    node* q = L.pHead;
    while (p != NULL && p->next != NULL) {
        p = p->next->next;
        q = q->next;
    }
    return q;
}


int main()
{
    List L;
    L.pHead = L.pTail = NULL;
    int n; cin >> n;
    inputList(L, n);
    cout << "Created List: " << endl;
    outputList(L);
    cout << endl;

    node* p = findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if (p)cout << "The middle element is " << p->info;

    return 0;
}
