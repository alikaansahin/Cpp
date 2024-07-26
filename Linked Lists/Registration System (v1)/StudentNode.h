//
// Created by ali20 on 20.05.2023.
//

#ifndef MAIN_CPP_STUDENTNODE_H
#define MAIN_CPP_STUDENTNODE_H
#include <iostream>
#include "CourseNode.h"

using namespace std;

class StudentNode {
public:
    StudentNode(int studentId, string firstName, string lastName);
    ~StudentNode();

    void setId(int studentId);

    int getId();

    string getFirstName();

    void setFirstName(string firstName);

    string getLastName();

    void setLastName(string lastName);

    CourseNode* getHead();

    void setHead(CourseNode* head);

    StudentNode* getNext();

    void setNext(StudentNode* next);

    StudentNode* getPrev();

    void setPrev(StudentNode* prev);
private:
    int studentId;
    string firstName;
    string lastName;
    CourseNode* courseHead;
    StudentNode* next;
    StudentNode* prev;

};


#endif //MAIN_CPP_STUDENTNODE_H
