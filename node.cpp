#include <iostream>

using std::cout;
using std::endl;

typedef struct Node {
    int iValue;
    Node* next;
} Node;

typedef struct Queue {
    Node* first;
    Node* last;
} Queue;

Node* newNode(int);
Queue* newQueue();
int firstQueue(Queue*);
int lastQueue(Queue*);
void addQueue(Queue*, int);
void popQueue(Queue*);
void printQueue(Queue*);

int main() {
    
    Queue* queue = newQueue();
    addQueue(queue, 1);
    cout << firstQueue(queue) << endl;
    cout << lastQueue(queue) << endl;
    cout << "---------------------------------" << endl;
    addQueue(queue, 1);
    addQueue(queue, 7);
    addQueue(queue, 12);
    addQueue(queue, -2);
    addQueue(queue, 0);
    cout << firstQueue(queue) << endl;
    cout << lastQueue(queue) << endl;
    cout << "---------------------------------" << endl;
    printQueue(queue);
    cout << "---------------------------------" << endl;
    popQueue(queue);
    popQueue(queue);
    printQueue(queue);
    
    
    return 0;
}

Node* newNode(int iValue) {
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node != NULL) {
        node->iValue = iValue;
        node->next = NULL;
    }
    return node;
}

Queue* newQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    
    if (queue != NULL) {
        queue->first = NULL;
        queue->last = NULL;
    }
    return queue;
}

int firstQueue(Queue* const queue) {
    return queue->first->iValue;
}

int lastQueue(Queue* const queue) {
    return queue->last->iValue;
}

void addQueue(Queue* queue, int iValue) {
    Node* node = newNode(iValue);
    
    if (queue->first != NULL) {
        queue->last->next = node;
        queue->last = node;
    } else {
        queue->first = node;
        queue->last = node;
    }
}

void popQueue(Queue* queue) {
    if (queue != NULL) {
        Node* temp = queue->first->next;
        free(queue->first);
        queue->first = temp;
    }
}

void printQueue(Queue* const queue) {
    Node* current;
    for(current = queue->first; current->next != NULL; current = current->next) {
        cout << current->iValue << " ";
    }
    cout << current->iValue << endl;
}
