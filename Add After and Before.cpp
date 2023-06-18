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

void addTail(DList& L, int x) {
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

DNode* Searchele(DList&L, int x) {
    DNode* pTemp = L.pHead;
    while (pTemp != NULL) {
        if (pTemp->info == x) {
            break;
        }
        pTemp = pTemp->pNext;
    }
    return pTemp;
}

bool Search(DList&L, int x) {
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
    if (!Search(L, x)) {
        cout << "\nCan't find the value " << x;
    }
    else {
        DNode* p = L.pHead;
        while (p != NULL) {
            if (p->info == x) {
                DNode* newele = getNode(y);
                newele->pPrev = p;
                newele->pNext = p->pNext;
                if (p == L.pTail) {
                    L.pTail = newele;
                }
                else {
                    p->pNext->pPrev = newele;
                }
                p->pNext = newele;
                break;
            }
            p = p->pNext;
        }
    }
}
void addBefore(DList& L, int x, int y) {
    if (!Search(L, x)) {
        cout << "\nCan't find the value " << x;
    }
    else {
        DNode* p = L.pHead;
        while (p != NULL) {
            if (p->info == x) {
                DNode* newele = getNode(y);
                newele->pNext = p;
                newele->pPrev = p->pPrev;
                if (p == L.pHead) {
                    L.pHead = newele;
                }
                else {
                    p->pPrev->pNext = newele;
                }
                p->pPrev = newele;
                break;
            }
            p = p->pNext;
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

void printList(DList L){
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

void addBeforeMulti(DList& L, int x, int y) {
    if (Search(L, x) == false) {
        cout << "\nCan't find the value " << x;
    }
    DNode* p = L.pHead;
    while (p != NULL) {
        if (p->info == x) {
            DNode* q = getNode(y);
            q->pPrev = p->pPrev;
            q->pNext = p;
            if (p == L.pHead) {
                L.pHead = q;
            }
            else {
                p->pPrev->pNext = q;
            }
            p->pPrev = q;
        }
        p = p->pNext;
    }
}

void addAfterMulti(DList& L, int x, int y) {
    if (Search(L, x) == false) {
        cout << "\nCan't find the value " << x;
    }
    DNode* p = L.pHead;
    while (p != NULL) {
        if (p->info == x) {
            DNode* q = getNode(y);
            q->pPrev = p;
            q->pNext = p->pNext;
            if (p == L.pTail) {
                L.pTail = q;
            }
            else {
                p->pNext->pPrev = q;
            }
            p->pNext = q;
        }
        p = p->pNext;
    }
}

void removeHead(DList& L) {
    if (L.pHead == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }
    else if (L.pHead == L.pTail) {
        char confirm;
        cout << "\nDo you want to delete the first element?(y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            delete L.pHead;
            L.pHead = L.pTail = NULL;
            cout << "\nThe list becomes empty";
        }
    }
    else {
        char confirm;
        cout << "\nDo you want to delete the first element?(y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            DNode* p = L.pHead;
            L.pHead = L.pHead->pNext;
            L.pHead->pPrev = NULL;
            delete p;
        }
    }
}

void removeTail(DList& L) {
    if (L.pHead == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }
    else if (L.pHead == L.pTail) {
        char confirm;
        cout << "\nDo you want to delete the last element?(y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            delete L.pTail;
            L.pHead = L.pTail = NULL;
            cout << "\nThe list becomes empty";
        }
    }
    else {
        char confirm;
        cout << "\nDo you want to delete the last element?(y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            DNode* p = L.pTail;
            L.pTail = L.pTail->pPrev;
            L.pTail->pNext = NULL;
            delete p;
        }
    }
}

void removeNode(DList& L, const int& x) {
    char confirm;
    if (!Search(L, x)) {
        cout << "\nCan't find the value " << x;
    }
    else {
        cout << "\nDo you want to delete " << x << "s ?(y/n): ";
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            return;
        }
        else {
            if (L.pHead == L.pTail && L.pHead->info == x) {
                delete L.pHead;
                L.pHead = L.pTail = nullptr;
                cout << "\nThe list becomes empty";
            }
            else {
                DNode* p = L.pHead;
                while (p != NULL && p->info != x) {
                    p = p->pNext;
                }
                if (p == nullptr) {
                    return;
                }
                if (p == L.pHead) {
                    L.pHead = p->pNext;
                    if (L.pHead != nullptr) {
                        L.pHead->pPrev = nullptr;
                    }
                }
                else if (p == L.pTail) {
                    L.pTail = p->pPrev;
                    if (L.pTail != nullptr) {
                        L.pTail->pNext = nullptr;
                    }
                }
                else {
                    p->pPrev->pNext = p->pNext;
                    p->pNext->pPrev = p->pPrev;
                }
                delete p;
            }
        }
    }
}

void removeMultiNodeS(DList& L, const int& x) {
    char confirm;
    if (!Search(L, x)) {
        cout << "\nCan't find the value " << x;
    }
    else {
        cout << "\nDo you want to delete " << x << "s ?(y/n): ";
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            return;
        }
        else {
            if (L.pHead == L.pTail && L.pHead->info == x) {
                delete L.pHead;
                L.pHead = L.pTail = nullptr;
                cout << "\nThe list becomes empty";
            }
            else {
                DNode* p = L.pHead;
                while (p != nullptr) {
                    if (p->info == x) {
                        if (p == L.pHead) {
                            L.pHead = p->pNext;
                            if (L.pHead != nullptr) {
                                L.pHead->pPrev = nullptr;
                            }
                        }
                        else if (p == L.pTail) {
                            L.pTail = p->pPrev;
                            if (L.pTail != nullptr) {
                                L.pTail->pNext = nullptr;
                            }
                        }
                        else {
                            p->pPrev->pNext = p->pNext;
                            p->pNext->pPrev = p->pPrev;
                        }
                        DNode* temp = p;
                        p = p->pNext;
                        delete temp;
                    }
                    else {
                        p = p->pNext;
                    }
                }
                if (L.pHead == nullptr) {
                    cout << "\nThe list becomes empty";
                }
            }
        }
    }
}

void removeAfter(DList& L, const int& x) {
    if (!Search(L, x)) {
        cout << "\nCan't find the value" << x;
    }
    else {
        char c;
        cout << "\nDo you want to delete the element after " << x << " ?(y/n): ";
        cin >> c;
        if (c != 'y' && c != 'Y') {
            return;
        }
        else {
            DNode* p = L.pHead;
            while (p != nullptr && p->info != x) {
                p = p->pNext;
            }
            if (p == nullptr) {
                return;
            }
            DNode* q = p->pNext;
            if (q == nullptr) {
                cout << endl << x << " is the last element. Can't delete the element after it";
                return;
            }
            while (q != nullptr && q->info == x) {
                q = q->pNext;
            }
            p->pNext = q->pNext;
            if (p->pNext != nullptr) {
                q->pNext->pPrev = p;
            }
            else {
                L.pTail = p;
            }
            delete q;

        }
    }

}

void removeBefore(DList& L, const int& x) {
    if (!Search(L, x)) {
        cout << "\nCan't find the value" << x;
    }
    else {
        char c;
        cout << "\nDo you want to delete the element before " << x << " ?(y/n): ";
        cin >> c;
        if (c != 'y' && c != 'Y') {
            return;
        }
        else {
            DNode* p = L.pHead;
            while (p != nullptr && p->info != x) {
                p = p->pNext;
            }
            if (p == nullptr) {
                return;
            }
            DNode* q = p->pPrev;
            if (q == nullptr) {
                cout << endl << x << " is the first element. Can't delete the element before it";
                return;
            }
            while (q != nullptr && q->info == x) {
                q = q->pNext;
            }
            if (q->pPrev != nullptr) {
                q->pPrev->pNext = p;
                p->pPrev = q->pPrev;
            }
            else {
                L.pHead = p;
            }
            delete q;
        }
    }
}

void removeMultiAfters(DList& L, const int& x)
{
    if (!Search(L, x)) {
        cout << "\nCan't find the value " << x;
        return;
    }
    else {
        int dem = 0;
        for (DNode* p = L.pHead; p != nullptr; p = p->pNext) {
            if (p->info == x) {
                DNode* temp = p->pNext;
                if (temp != NULL && temp->info != x) {
                    dem++;
                }
            }
        }
        if (dem == 0 && L.pTail->info == x && L.pHead->info != x) {
            cout << "\nList has only one " << x << " and " << x << " is the last element. Can't delete the element after it";
            return;
        }
        
        else {
            char c;
            cout << "\nDo you want to delete all elements after " << x << " ?(y/n): ";
            cin >> c;
            if (c != 'y' && c != 'Y') {
                return;
            }
            else {
                DNode* p = L.pHead;
                while (p != nullptr) {
                    if (p->info == x) {
                        DNode* q = p->pNext;
                        p->pNext = q->pNext;
                        if (q->pNext != nullptr) {
                            q->pNext->pPrev = p;
                        }
                        else {
                            L.pTail = p;
                        }
                        delete q;
                    }
                    p = p->pNext;
                }
            }
        }
    }
}

void removeMultiBefores(DList& L, const int& x) {
    if (!Search(L, x)) {
        cout << "\nCan't find the value " << x;
        return;
    }
    else {
        int dem = 0;
        for (DNode* p = L.pHead; p != NULL; p = p->pNext) {
            if (p->info == x) {
                dem++;
            }
        }
        if (dem == 1 && L.pHead->info == x && L.pTail->info != x) {
            cout << "\nList has only one " << x << " and " << x << " is the first element. Can't delete the element before it";
            return;
        }
        else {
            char c;
            cout << "\nDo you want to delete all elements before " << x << " ?(y/n): ";
            cin >> c;
            if (c != 'y' && c != 'Y') {
                return;
            }
            else {
                DNode* p = L.pHead;
                while (p != NULL) {
                    if (p->info == x) {
                        DNode* q = p->pPrev;
                        p->pPrev = q->pPrev;
                        if (p->pPrev != NULL) {
                            q->pPrev->pNext = p;
                        }
                        else {
                            L.pHead = p;
                        }
                        delete q;
                    }
                    p = p->pNext;
                }
            }
        }
    }
}

void removeAll(DList& L) {
    char c;
    cout << "\nDo you want to delete all elements?(y/n): ";
    cin >> c;
    if (c != 'y' && c != 'Y') {
        return;
    }
    else {
        DNode* p = L.pHead;
        while (p != NULL) {
            DNode* q = p;
            p = p->pNext;
            delete q;
        }
        L.pHead = NULL;
        L.pTail = NULL;
        cout << "\nThe list becomes empty";
    }
}


int main()
{
    DList L;
    init(L);
    int x, y, choice; char c;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n9. Delete the first element";
    cout << "\n10. Delete the last element";
    cout << "\n11. Delete the first element containing a specific value";
    cout << "\n12. Delete all elements storing a particular value";
    cout << "\n13. Delete the element after a specific value (only for the first one found)";
    cout << "\n14. Delete the element before a specific value (only for the first one found)";
    cout << "\n15. Delete all elements after a specific value";
    cout << "\n16. Delete all elements before a specific value";
    cout << "\n17. Delete all elements";
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
        case 7:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfterMulti(L, x, y);
            break;
        case 8:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBeforeMulti(L, x, y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeNode(L, x);
            break;
        case 12:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiNodeS(L, x);
            break;
        case 13:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeAfter(L, x);
            break;
        case 14:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeBefore(L, x);
            break;
        case 15:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiAfters(L, x);
            break;
        case 16:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiBefores(L, x);
            break;
        case 17:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            removeAll(L);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;

        }
    }

    return 0;
}



