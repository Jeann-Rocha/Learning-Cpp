#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node {
    int iPayLoad;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

typedef struct Cicle {
    Node* head;
    Node* tail;
} Cicle;

Node* createNode(int iPayLoad) {
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node != nullptr) {
        node->iPayLoad = iPayLoad;
        node->ptrPrev = nullptr;
        node->ptrNext = nullptr;
    }
    return node;
}

Cicle* createCicle() {
    Cicle* cicle = (Cicle*) malloc(sizeof(Cicle));
    
    if (cicle != nullptr) {
        cicle->head = nullptr;
        cicle->tail = nullptr;
    }
    return cicle;
}

void printCicle(Cicle* cicle) {
    if (cicle == nullptr) {
        cout << "Lista Vazia" << endl;
        return;
    }
    
    Node* current;
    for (current = cicle->head; current->ptrNext != cicle->head; current = current->ptrNext) {
        cout << current->iPayLoad << " ";
    }
    cout << current->iPayLoad << endl;
}

void addElement(Cicle* cicle, int iPayLoad) {
    Node* node = createNode(iPayLoad);
    
    if (cicle->head == nullptr) {
        cicle->head = node;
        cicle->tail = node;
        cicle->head->ptrNext = cicle->tail;
        cicle->head->ptrPrev = cicle->tail;
        cicle->tail->ptrNext = cicle->head;
        cicle->tail->ptrPrev = cicle->head;
    } else {
        cicle->tail->ptrNext = node;
        node->ptrPrev = cicle->tail;
        node->ptrNext = cicle->head;
        cicle->head->ptrPrev = node;
        cicle->tail = node;
    }
}

Cicle* createCiclebyArray(int* arr, int iSize) {
    Cicle* cicle = createCicle();
    
    for (int i = 0; i < iSize; i++) {
        addElement(cicle, arr[i]);
    }
    return cicle;
}

int updateUp(Cicle* cicle) {
    if (cicle->head == nullptr) {
        cout << "Lista Vazia" << endl;
        return 0;
    }
    
    int iPayLoad = cicle->head->iPayLoad;
    cicle->head = cicle->head->ptrNext;
    cicle->tail = cicle->tail->ptrNext;
    
    return iPayLoad;
}

int updateDown(Cicle* cicle) {
    if (cicle->head == nullptr) {
        cout << "Lista Vazia" << endl;
        return 0;
    }
    
    int iPayLoad = cicle->head->iPayLoad;
    cicle->head = cicle->head->ptrPrev;
    cicle->tail = cicle->tail->ptrPrev;
    
    return iPayLoad;
}

void removeNode(Cicle* cicle, Node* node) {
    if (cicle->head == nullptr) {
        cout << "Lista Vazia" << endl;
        return;
    }
    
    if (node == nullptr) {
        cout << "Nó Vazio" << endl;
        return;
    }

    if (node == cicle->head) {
        cicle->head = node->ptrNext;
    } else if (node == cicle->tail) {
        cicle->tail = node->ptrPrev;
    }
    
    node->ptrPrev->ptrNext = node->ptrNext;
    node->ptrNext->ptrPrev = node->ptrPrev;
    node->ptrPrev = nullptr;
    node->ptrNext = nullptr;
    
    free(node);
}

void deleteCicle(Cicle* cicle) {
    // falta fazer!
}

Cicle* intercallCicles(Cicle* cicle1, Cicle* cicle2) {
    Cicle* cicle = createCicle();
    
    Node* current1;
    Node* current2;
    
    for (current1 = cicle1->head, current2 = cicle2->head; (current1->ptrNext != cicle1->head && current2->ptrNext != cicle2->head); current1 = current1->ptrNext, current2 = current2->ptrNext) {
        addElement(cicle, current1->iPayLoad);
        addElement(cicle, current2->iPayLoad);
    }
    
    if (current1->ptrNext != cicle1->head) {
        while (current1->ptrNext != cicle1->head) {
            addElement(cicle, current1->iPayLoad);
            current1 = current1->ptrNext;
        }
        addElement(cicle, current1->iPayLoad);
    } else if (current2->ptrNext != cicle2->head) {
        while (current2->ptrNext != cicle2->head) {
            addElement(cicle, current2->iPayLoad);
            current1 = current1->ptrNext;
        }
        addElement(cicle, current2->iPayLoad);
    } else {
        addElement(cicle, current1->iPayLoad);
        addElement(cicle, current2->iPayLoad);
    }
    
    return cicle;
}

int main() {
    
    int arr[10] = {9, 2, 44, -2, 77, 9, 0, 0, 12, -999};
    Cicle* cicle = createCiclebyArray(arr, 10);
    printCicle(cicle);
    cout << updateUp(cicle) << endl;
    removeNode(cicle, cicle->head->ptrNext->ptrNext);
    printCicle(cicle);
    
    int arr2[7] = {1, 2, 3, 4, 5, 6, 7};
    Cicle* cicle2 = createCiclebyArray(arr2, 7);
    printCicle(cicle2);
    Cicle* cicle3 = intercallCicles(cicle, cicle2);
    
    printCicle(cicle3);
    cout << cicle->tail->iPayLoad << endl;
    
    return 0;
}
