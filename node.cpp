#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct Node {
    int iValue;
    Node* next;
} Node;

Node* newNode(int iValue) {
    Node* node = (Node*) malloc(sizeof(Node));

    if (node != nullptr) {
        node->iValue = iValue;
        node->next = NULL;
    }
    return node;
}

void addNode(Node* list, int iValue) {
    Node* temp = newNode(iValue);
    
    Node* current;
    for(current = list; current->next != nullptr; current=current->next);
    current->next=temp;
}

void printList(Node* list) {
    Node* current;
    for(Node* current = list; current->next != nullptr; current=current->next) {
        cout << current->iValue << " ";
    }
    cout << current->iValue << endl;
}

int sizeList(Node* list) {
    int iSize = 1;
    for(Node* current = list; current->next != nullptr; current=current->next, iSize++);
    return iSize;
}

int firstElement(Node* list) {
    return list->iValue;
}

int main() {
    
    Node* list = newNode(1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 1);
    addNode(list, 7);
    addNode(list, 7);
    
    cout << "first: " << firstElement(list) << endl;
    printList(list);
    cout << "size: " << sizeList(list) << endl;
    
    return 0;
}

