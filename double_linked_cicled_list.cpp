#include <iostream>
#include <cstdlib>
#include <math.h>

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

// -------------------- FUNÇÕES PARA LISTA CÍCLICA DUPLAMENTE ENCADEADA --------------------

Cicle* createCicle();
void printCicle(Cicle*);
void addElementCicle(Cicle*, int);
Cicle* createCiclebyArray(int*, int);
int updateUp(Cicle*);
int updateDown(Cicle*);
void removeNode(Cicle*, Node*);
void deleteCicle(Cicle*); // falta fazer
Cicle* intercallCicles(Cicle*, Cicle*);

Cicle* Ouroboros(int, int);

// -------------------- FUNÇÕES PARA LISTA DUPLAMENTE ENCADEADA --------------------

Node* createNode(int); // essencial para lista cíclica também
void printList(Node**);
void addElementList(Node**, int iPayLoad);
bool thereCicle(Node**);



int main() {
    
    // Seja Bem-Vindo a Questao 1 (^_^): PLAYLIST DE ELON LAGES
    
    // Criando uma Lista Cíclica por um Array
    int arr1[10] = {9, 2, 44, -2, 77, 9, 0, 0, 12, -999};
    Cicle* cicle1 = createCiclebyArray(arr1, 10);
    cout << "Ciclo 1: "; printCicle(cicle1);
    
    // Retornar ID e avançar a Lista
    cout << "ID (Ciclo 1): "; cout << updateUp(cicle1) << endl;
    cout << "Ciclo 1 - Apos Avancar: "; printCicle(cicle1);

    // Retornar ID e retroceder a Lista    
    cout << "ID (Ciclo 1): "; cout << updateDown(cicle1) << endl;
    cout << "Ciclo 1 - Apos Retroceder: "; printCicle(cicle1);
    
    // Removendo nó
    cout << "Removendo Primeiro Nó: "; removeNode(cicle1, cicle1->head->ptrNext->ptrNext);
    printCicle(cicle1);
    
    // Intercalando Listas
    int arr2[7] = {1, 2, 3, 4, 5, 6, 7};
    Cicle* cicle2 = createCiclebyArray(arr2, 7);
    cout << "Ciclo 2: "; printCicle(cicle2);
    Cicle* cicle3 = intercallCicles(cicle1, cicle2);
    cout << "Ciclo 3: "; printCicle(cicle3);
    
    cout << "===============================================================================" << endl;
    
    // Seja Bem-Vindo a Questao 2 (^_^): LOOP EM LISTA DUPLAMENTE ENCADEADA
    
    // Crianfo Lista
    Node* list1 = createNode(0);
    for (int i = 1; i < 10; i++) {
        addElementList(&list1, i);
    }
    cout << "Lista 1: "; printList(&list1);
    
    // Criando um Loop na Lista Criada
    
    Node* current;
    for (current = list1; current->ptrNext != nullptr; current = current->ptrNext);
    current->ptrNext = list1;
    list1->ptrPrev = current;
    
    // Verificando se há Loop na Lista Acima
    cout << "Há ciclo na Lista 1 (1 - SIM, 0 - NÃO): " << thereCicle(&list1) << endl;
    
    // Verificando se há Loop numa Lista sem Loop
    Node* list2 = createNode(0);
    for (int i = 1; i < 10; i++) {
        addElementList(&list2, i);
    }
    cout << "Lista 2: "; printList(&list2);
    
    cout << "Há ciclo na Lista 2 (1 - SIM, 0 - NÃO): " << thereCicle(&list2) << endl;
    
    cout << "===============================================================================" << endl;
    
    // Seja Bem-Vindo a Questao 3 (^_^): OUROBOROS
    
    // Validando Ouroboros Final = 320 -> (1, 2, 3)
    
    Cicle* cicle4 = Ouroboros(320, 3);
    cout << "OUROBOROS para (320, 3): "; printCicle(cicle4);
    
    // Validando Ouroboros Final = 12 -> (1, 1, 1)
    
    Cicle* cicle5 = Ouroboros(12, 3);
    cout << "OUROBOROS para (12, 3): "; printCicle(cicle5);
    
    // Validando Ouroboros Final = pow(2, 19) * 7 -> (1, 2, 3, 1)
    
    Cicle* cicle6 = Ouroboros(pow(2, 19) * 7, 4);
    cout << "OUROBOROS para (7*2^19, 4): "; printCicle(cicle6);
    
    cout << "===============================================================================" << endl;
    
    // falta deletar ciclos e listas
    
    cout << "Finalizando o Programa, BYE BYE (^_^) ..." << endl;
    
    return 0;
}

// -------------------- FUNÇÕES PARA LISTA CÍCLICA DUPLAMENTE ENCADEADA --------------------

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

void addElementCicle(Cicle* cicle, int iPayLoad) {
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
        addElementCicle(cicle, arr[i]);
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
        addElementCicle(cicle, current1->iPayLoad);
        addElementCicle(cicle, current2->iPayLoad);
    }
    
    if (current1->ptrNext != cicle1->head) {
        addElementCicle(cicle, current2->iPayLoad);
        while (current1->ptrNext != cicle1->head) {
            addElementCicle(cicle, current1->iPayLoad);
            current1 = current1->ptrNext;
        }
        addElementCicle(cicle, current1->iPayLoad);
    } else if (current2->ptrNext != cicle2->head) {
        addElementCicle(cicle, current1->iPayLoad);
        while (current2->ptrNext != cicle2->head) {
            addElementCicle(cicle, current2->iPayLoad);
            current1 = current1->ptrNext;
        }
        addElementCicle(cicle, current2->iPayLoad);
    } else {
        addElementCicle(cicle, current1->iPayLoad);
        addElementCicle(cicle, current2->iPayLoad);
    }
    
    return cicle;
}

// -------------------- FUNÇÕES PARA LISTA DUPLAMENTE ENCADEADA --------------------

Node* createNode(int iPayLoad) {
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node != nullptr) {
        node->iPayLoad = iPayLoad;
        node->ptrPrev = nullptr;
        node->ptrNext = nullptr;
    }
    return node;
}

void printList(Node** head) {
    if (*head == nullptr) {
        cout << "Lista Vazia" << endl;
        return;
    }
    
    Node* current;
    for (current = *head; current->ptrNext != nullptr; current = current->ptrNext) {
        cout << current->iPayLoad << " ";
    }
    cout << current->iPayLoad << endl;
}

void addElementList(Node** head, int iPayLoad) {
    Node* temp = createNode(iPayLoad);
        
    if (*head == nullptr) {
        *head = temp;
    } else {
        Node* current;
        for (current = *head; current->ptrNext != nullptr; current = current->ptrNext);
        current->ptrNext = temp;
        temp->ptrPrev = current;
    }
}

bool thereCicle(Node** head) {
    if ((*head)->ptrPrev == nullptr) {
        return false;
    } else {
        return true;
    }
}

Cicle* Ouroboros(int iFinal, int iSize) {
    Cicle* cicle = createCicle();
    addElementCicle(cicle, iFinal);
    
    int iA, iB;
    for (int i = 0; i < iSize - 1; i++) {
        iA = 0, iB = 0;
        while ((cicle->head->iPayLoad % ((int) pow(2, iA))) == 0) {
            iA += 1;
        }
        iA -= 1;
        int iB = cicle->head->iPayLoad / pow(2, iA);
        iB = (iB - 1) / 2;
        addElementCicle(cicle, iB);
        cicle->head->iPayLoad = iA + 1;
    }
    
    return cicle;
}
