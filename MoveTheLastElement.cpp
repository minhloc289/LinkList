
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

void moveLastToFront(List& L) {
    if (L.pHead != NULL && L.pHead->next != NULL) {
        node* p = L.pHead;
        node* q = NULL;
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        p->next = L.pHead;
        L.pHead = p;
        if (L.pTail == p) {
            L.pTail = q;
        }
    }

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

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout << "Updated List after moving the last element to front of L: " << endl;
    outputList(L);
    return 0;
}
