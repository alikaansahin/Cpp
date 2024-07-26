#ifndef HW3_LAST_TRANSACTIONLINKEDLIST_H
#define HW3_LAST_TRANSACTIONLINKEDLIST_H

#include "iostream"
#include "CourseNode.h"

class CourseLinkedList {
public:


    CourseNode* head;
    CourseLinkedList();
    CourseLinkedList(int movie, bool is);
    void add(int id);
    bool remove(int id);
    ~CourseLinkedList();
};

#endif //HW3_LAST_TRANSACTIONLINKEDLIST_H
