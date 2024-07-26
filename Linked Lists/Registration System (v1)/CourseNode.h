//
// Created by ali20 on 20.05.2023.
//

#ifndef MAIN_CPP_COURSENODE_H
#define MAIN_CPP_COURSENODE_H
#include <iostream>
#include "CourseNode.h"

using namespace std;

class CourseNode {
public:
    CourseNode(int courseId, string courseName);
    ~CourseNode();
    void setId(int courseId);

    int getId();

    string getName();

    void setName(string courseName);

    void setNext(CourseNode* next);

    CourseNode* getNext();

private:
    int courseId;
    string courseName;
    CourseNode* next;
};


#endif //MAIN_CPP_COURSENODE_H
