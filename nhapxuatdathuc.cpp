#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC {
	int somu;
	double heso;
};


struct Node {
	DONTHUC* data;
	Node* next;

};


typedef struct DATHUC {
	Node* head;
	Node* tail;
}List;


void Nhap(DATHUC& B) {
    B.head = B.tail = NULL;
    int n;
    double heso;
    int somu;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heso >> somu;
        Node* p = new Node;
        p->data = new DONTHUC{ somu, heso };
        p->next = NULL;
        if (B.head == NULL) {
            B.head = B.tail = p;
        }
        else {
            B.tail->next = p;
            B.tail = p;
        }
    }
}

void Xuat(DATHUC B) {
    bool daThucRong = true;
    Node* p = B.head;
    while (p != NULL) {
        if (p->data->heso != 0) {
            daThucRong = false;
        }
        p = p->next;
    }
    if (daThucRong) {
        cout << "0" << endl;
        return;
    }
    p = B.head;
    bool firstTerm = true;
    while (p != NULL) {
        if (p->data->heso != 0) {
            if (!firstTerm && p->data->heso > 0) {
                cout << "+";
            }
            firstTerm = false;
            if (p->data->somu == 0) {
                cout << p->data->heso;
            }
            else if (p->data->somu == 1) {
                if (p->data->heso == 1) {
                    cout << "x";
                }
                else if (p->data->heso == -1) {
                    cout << "-x";
                }
                else {
                    cout << p->data->heso << "x";
                }
            }
            else {
                if (p->data->heso == 1) {
                    cout << "x^" << p->data->somu;
                }
                else if (p->data->heso == -1) {
                    cout << "-x^" << p->data->somu;
                }
                else {
                    cout << p->data->heso << "x^" << p->data->somu;
                }
            }
        }
        p = p->next;
    }
    cout << endl;
}

DATHUC Tong2DaThuc(DATHUC A, DATHUC B) {
    DATHUC C;
    C.head = C.tail = NULL;
    Node* pA = A.head;
    Node* pB = B.head;
    while (pA != NULL && pB != NULL) {
        if (pA->data->somu == pB->data->somu) {
            double heso = pA->data->heso + pB->data->heso;
            if (heso != 0) {
                Node* newNode = new Node;
                newNode->data = new DONTHUC{ pA->data->somu, heso };
                newNode->next = NULL;
                if (C.head == NULL) {
                    C.head = C.tail = newNode;
                }
                else {
                    C.tail->next = newNode;
                    C.tail = newNode;
                }
            }
            pA = pA->next;
            pB = pB->next;
        }
        else if (pA->data->somu > pB->data->somu) {
            Node* newNode = new Node;
            newNode->data = new DONTHUC{ pA->data->somu, pA->data->heso };
            newNode->next = NULL;
            if (C.head == NULL) {
                C.head = C.tail = newNode;
            }
            else {
                C.tail->next = newNode;
                C.tail = newNode;
            }
            pA = pA->next;
        }
        else {
            Node* newNode = new Node;
            newNode->data = new DONTHUC{ pB->data->somu, pB->data->heso };
            newNode->next = NULL;
            if (C.head == NULL) {
                C.head = C.tail = newNode;
            }
            else {
                C.tail->next = newNode;
                C.tail = newNode;
            }
            pB = pB->next;
        }
    }
    while (pA != NULL) {
        Node* newNode = new Node;
        newNode->data = new DONTHUC{ pA->data->somu, pA->data->heso };
        newNode->next = NULL;
        if (C.head == NULL) {
            C.head = C.tail = newNode;
        }
        else {
            C.tail->next = newNode;
            C.tail = newNode;
        }
        pA = pA->next;
    }
    while (pB != NULL) {
        Node* newNode = new Node;
        newNode->data = new DONTHUC{ pB->data->somu, pB->data->heso };
        newNode->next = NULL;
        if (C.head == NULL) {
            C.head = C.tail = newNode;
        }
        else {
            C.tail->next = newNode;
            C.tail = newNode;
        }
        pB = pB->next;
    }
    return C;
}

int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}



