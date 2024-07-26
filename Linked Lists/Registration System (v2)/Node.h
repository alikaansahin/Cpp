//
// Created by anili on 13.12.2022.
//

#ifndef HW3_LAST_NODE_H
#define HW3_LAST_NODE_H
#include "iostream"

class Node {
public:
    int id;
    Node* nextNode;
    int count;
    Node(int i, int c){ id = i; count = c; nextNode = NULL;}
};
#endif //HW3_LAST_NODE_H
