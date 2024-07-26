#ifndef HW3_LAST_TRANSACTIONNODE_H
#define HW3_LAST_TRANSACTIONNODE_H
#include "iostream"

class CourseNode {
public:
    int movieId;
    bool isReturned;
    CourseNode* nextNode;
    CourseNode(int movie, bool is){ movieId = movie; nextNode = NULL; isReturned = is;}
};
#endif //HW3_LAST_TRANSACTIONNODE_H
