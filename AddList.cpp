
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

void Init(List& L)
{
    L.head = L.tail = NULL;
}

bool isEmpty(List L)
{
    return L.head == NULL;
}

Node* createNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->next = NULL;
    return p;
}

void addTail(List& L, int value)
{
    Node* p = createNode(value);
    if (isEmpty(L))
    {
        L.head = L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void outputList(List L)
{
    if (isEmpty(L))
    {
        cout << "List is empty";
    }
    else {
        Node* p = L.head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

void inputList(List& L, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        addTail(L, value);
    }
}

void addHead(List& L, int value)
{
    Node* p = createNode(value);
    if (isEmpty(L)) {
        L.head = L.tail = p;
    }
    else {
        p->next = L.head;
        L.head = p;
    }
}

void addList(List& L, int m)
{
    for (int i = 1; i <= m; i++)
    {
        int value;
        cin >> value;
        addHead(L, value);
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

    cout << "\nEnter a number: "; int m; cin >> m; // Nhap so luong phan tu them vao dau ds
    cout << "\nEnter a sequence of " << m << " numbers: ";
    addList(L, m); // Nhap 1 day gom m so va them phan tu moi vao dau ds
    cout << "\nThe updated Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}

