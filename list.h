#ifndef LIST_H
#define LIST_H
#include <iostream>
struct Node {
    Node* next;
    int value;
};

Node* mergeLists(Node*, Node*);
void printList(Node*);
Node* mergeLists(Node* lhs, Node* rhs)
{
    if(!lhs && !rhs) return nullptr;
    Node* mergeList = new Node;
    Node* out = mergeList;
    while (lhs || rhs) {
        if(lhs == nullptr) goto rhgs;
        if(rhs == nullptr) goto lhgs;
        if(lhs->value <= rhs->value) {
            lhgs:
            mergeList->value = lhs->value;
            lhs = lhs->next;
        }
        else {
            rhgs:
            mergeList->value = rhs->value;
            rhs = rhs->next;
        }
        if(!rhs && !lhs) return out;
        mergeList->next = new Node;
        mergeList = mergeList->next;
    }
    return out;
}
void printList(Node* list) {
    while(list) {
        std::cout << list->value << ' ';
        list = list->next;
    }
    std::cout << std::endl;
}

#endif // LIST_H
