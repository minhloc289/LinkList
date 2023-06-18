#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef struct Province {
    int id;
    string name;
    int pop;
    double area;
}pro;

struct node {
    pro info;
    node* next;
};

struct List {
    node* pHead;
    node* tail;
};

void Init(List& L) {
    L.pHead = NULL;
    L.tail = NULL;
}

void inputProvine(pro& x) {
    cin >> x.id;
    cin.ignore();
    getline(cin, x.name);
    cin >> x.pop;
    cin >> x.area;
}

void outputProvince(pro x) {
    cout << x.id << "\t" << x.name << "\t" << x.pop << "\t" << x.area << endl;
}

node* getNode(pro x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void AddTail(List& L, pro x) {
    node* newele = getNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = newele;
        L.tail = newele;
    }
    else
    {
        L.tail->next = newele;
        L.tail = newele;
    }
}

void AddHead(List& L, pro x) {
    node* newele = getNode(x);
    if (L.pHead == NULL) {
        L.pHead = newele;
        L.tail = newele;
    }
    else {
        newele->next = L.pHead;
        L.pHead = newele;
    }
}

void inputListProvinces(List& L) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pro x;
        inputProvine(x);
        AddTail(L, x);
    }
}

void outputListProvinces(List L) {
    node* pTemp = L.pHead;
    if (L.pHead == NULL) {
        cout << "List is empty";
        return;
    }
    else {
        while (pTemp != NULL) {
            outputProvince(pTemp->info);
            pTemp = pTemp->next;
        }
    }
    
}


//void removeProvince(List& L, string name) {
//    node* pCur = L.head;
//    node* pPrev = NULL;
//    while (pCur != NULL) {
//        if (pCur->info.name == name) {
//            if (pPrev == NULL) {
//                L.head = pCur->next;
//            }
//            else {
//                pPrev->next = pCur->next;
//            }
//            if (pCur == L.tail) {
//                L.tail = pPrev;
//            }
//            delete pCur;
//            if (L.head == NULL) {
//                cout << endl;
//                cout << "Updated List:" << endl;
//                cout << "ID\t|Province\t|Population\t|Area" << endl;
//                cout << "List is empty";
//            }
//            else {
//                cout << endl;
//                cout << "Updated List:" << endl;
//                cout << "ID\t|Province\t|Population\t|Area" << endl;
//                outputListProvinces(L);
//            }
//            return;
//        }
//        pPrev = pCur;
//        pCur = pCur->next;
//    }
//    cout << "Not found" << endl;
//

//bool endsWith(string str, string s) {
//    if (s.length() > str.length()) {
//        return false;
//    }
//    return str.compare(str.length() - s.length(), s.length(), s) == 0;
//}
//
//void removesomeProvinces(List& L, string x) {
//    node* pCur = L.head;
//    node* pPrev = NULL;
//    bool removed = false;
//    while (pCur != NULL) {
//        if (endsWith(pCur->info.name, x)) {
//            if (pPrev == NULL) {
//                L.head = pCur->next;
//            }
//            else {
//                pPrev->next = pCur->next;
//            }
//            if (pCur == L.tail) {
//                L.tail = pPrev;
//            }
//            node* pTemp = pCur;
//            pCur = pCur->next;
//            delete pTemp;
//            removed = true;
//        }
//        else {
//            pPrev = pCur;
//            pCur = pCur->next;
//        }
//    }
//    if (removed) {
//        if (L.head == NULL) {
//            cout << "Updated List:" << endl;
//            cout << "ID\t|Province\t|Population\t|Area" << endl;
//            cout << "List is empty";
//        }
//        else {
//            cout << "Updated List:" << endl;
//            cout << "ID\t|Province\t|Population\t|Area" << endl;
//            outputListProvinces(L);
//        }
//    }
//    else {
//        cout << "Not found";
//        return;
//    }
//}
void removeList(List& L) {
    node* p = L.pHead;
    while (p != NULL) {
        node* temp = p;
        p = p->next;
        delete temp;
    }
    L.pHead = NULL;
    L.tail = NULL;
   
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);

    if (L.pHead)
    {
        cout << "Delete all:" << endl;
        removeList(L);
        outputListProvinces(L);
    }
    return 0;
}
