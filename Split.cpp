
#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head, * tail;
};

void list_initializing(List& l) {
    l.head = l.tail = NULL;
}
void add_tail(List& l, int x) {
    Node* p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List& l) {
    for (Node* p = l.head; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

pair<List, List> split(List& l) {
    List l1, l2;
    list_initializing(l1);
    list_initializing(l2);

    Node* p1 = NULL;
    Node* p2 = NULL;

    int i = 1;
    for (Node* p = l.head; p != NULL; p = p->next) {
        if (i % 2 == 1) {
            if (p1 == NULL) {
                l1.head = p;
            }
            else {
                p1->next = p;
            }
            p1 = p;
        }
        else {
            if (p2 == NULL) {
                l2.head = p;
            }
            else {
                p2->next = p;
            }
            p2 = p;
        }
        i++;
    }

    p1->next = NULL;
    p2->next = NULL;

    l1.tail = p1;
    l2.tail = p2;

    return { l1, l2 };
}

int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do {
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while (true);


    pair<List, List> ls = split(l);

    xuat(ls.first);
    xuat(ls.second);

    return 0;
}

