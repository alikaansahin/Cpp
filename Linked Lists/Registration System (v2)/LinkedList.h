#ifndef HW3_LAST_LINKEDLIST_H
#define HW3_LAST_LINKEDLIST_H
#include "Node.h"
using namespace std;

class LinkedList {
public:

    Node* linkedListHead;
    LinkedList();
    LinkedList(int id, int c);
    void add(int id, int c);
    bool remove(int id);
    void printLinkedlist();
    ~LinkedList();
};
#endif //HW3_LAST_LINKEDLIST_H
