#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode* pNext, * pPrev;
};

struct DList
{
	DNode* pHead, * pTail;
};

void init(DList& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

DNode* getNode(int x) {
    DNode* p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void addHead(DList& L, int x) {
    DNode* newele = getNode(x);
    if (L.pHead == NULL) {
        L.pHead = newele;
        L.pTail = newele;
    }
    else {
        L.pHead->pPrev = newele;
        newele->pNext = L.pHead;
        L.pHead = newele;
    }
}

void addTail(DList &L, int x) {
    DNode* newele = getNode(x);
    if (L.pHead == NULL) {
        L.pHead = newele;
        L.pTail = newele;
    }
    else {
        L.pTail->pNext = newele;
        newele->pPrev = L.pTail;
        L.pTail = newele;
    }
}

DNode* Searchele(DList L, int x) {
    DNode* pTemp = L.pHead;
    while (pTemp != NULL) {
        if (pTemp->info == x) {
            break;
        }
        pTemp = pTemp->pNext;
    }
    return pTemp;
}

bool Search(DList L, int x) {
    DNode* pTemp = L.pHead;
    while (pTemp != NULL) {
        if (pTemp->info == x) {
            return true;
        }
        pTemp = pTemp->pNext;
    }
    return false;
}

void addAfter(DList& L, int x, int y) {
    if (Search(L, x) == false) {
        cout << "\nCan't find the value " << x;
    }
    else {
        Searchele(L, x);
        DNode* p = L.pHead;
        if (p == NULL) {
            addHead(L, x);
        }
        else if (p == L.pTail) {
            addTail(L, x);
        }
        else {
            DNode* newele = getNode(x);
            newele->pPrev = p;
            newele->pNext = p->pNext;
            p->pNext->pPrev = newele;
            p->pNext = newele;
            
        }
    }
}
void addBefore(DList L, int x, int y) {
    if (Search(L, x) == false) {
        cout << "\nCan't find the value " << x;
    }
    else {
        Searchele(L, x);
        DNode* p = L.pHead;
        if (p == NULL) {

        }
    }
}
void createList(DList& L) {
    int x;
    while (1) {
        cin >> x;
        if (x == -1) {
            break;
        }
        else {
            addTail(L, x);
        }
        
    }
}

void printList(DList L) {
    if (L.pHead == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        DNode* p = L.pHead;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}


int main()
{
    DList L;
    init(L);
    int x, y, choice;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n20. Exit" << endl;

    while (true)
    {
        cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout << "\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout << "\nEnter a number: ";
            cin >> x;
            addHead(L, x);
            break;
        case 4:
            cout << "\nEnter a number: ";
            cin >> x;
            addTail(L, x);
            break;
        case 5:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfter(L, x, y);
            break;
        case 6:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBefore(L, x, y);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;

        }
    }

    return 0;
}
