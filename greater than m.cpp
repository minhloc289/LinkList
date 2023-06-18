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

void outputGreaterThan(List L, int m) {
    bool flag = false;
    if (L.head == NULL) {
        cout << "List is empty";
    }
    else {
        node* p = L.head;
        for (p = L.head; p != NULL; p = p->next) {
            if (p->info > m) {
                cout << p->info << " ";
                flag = true;
            }
        }
        if (flag == false) {
            cout << "None";
        }
    }
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout << "Enter a number: "; cin >> n; // Nhap so luong phan tu cua ds
    cout << "\nEnter a sequence of " << n << " numbers: ";
    inputList(L, n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout << "\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout << "\nEnter a number: "; int m; cin >> m;
    cout << "\nValues greater than " << m << ": ";
    outputGreaterThan(L, m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}