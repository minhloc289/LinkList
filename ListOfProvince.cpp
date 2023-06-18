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
    node* head;
    node* tail;
};



void Init(List& L) {
    L.head = NULL;
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
    node* pTemp = L.head;
    while (pTemp != NULL) {
        outputProvince(pTemp->info);
        pTemp = pTemp->next;
    }
}

void outputProvincesMore1MillionPop(List L) {
    node* pTemp = L.head;
    while (pTemp != NULL) {
        if (pTemp->info.pop > 1000) {
            outputProvince(pTemp->info);
        }
        pTemp = pTemp->next;
    }
}

node* findProMaxArea(List L) {
    node* max = L.head;
    node* pTemp = new node;
    for (pTemp = L.head; pTemp != NULL; pTemp = pTemp->next) {
        if (pTemp->info.area > max->info.area) {
            max = pTemp;
        }
    }
    return max;

}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);

    cout << "Provinces with a population of more than 1 million:" << endl;
    outputProvincesMore1MillionPop(L);

    cout << "The largest province:" << endl;
    node* p = findProMaxArea(L);
    if (p) outputProvince(p->info);

    return 0;
}




