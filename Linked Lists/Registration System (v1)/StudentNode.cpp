//
// Created by ali20 on 20.05.2023.
//

#include "StudentNode.h"

StudentNode::StudentNode(int studentId, string firstName, string lastName) {
    setId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
    courseHead = NULL;
    next = NULL;
    prev = NULL;
}

StudentNode::~StudentNode() {
    if (courseHead != NULL) {
        CourseNode *curr = courseHead;
        while (curr != NULL) {
            CourseNode *temp = curr->getNext();
            delete curr;
            curr = temp;
        }
    }
    courseHead = NULL;
    next = NULL;
    prev = NULL;
}
int StudentNode::getId() {
    return this->studentId;
}
void StudentNode::setId(int studentId) {
    this->studentId = studentId;
}
string StudentNode::getFirstName() {
    return this->firstName;
}
void StudentNode::setFirstName(string firstName) {
    this->firstName = firstName;
}
string StudentNode::getLastName() {
    return this->lastName;
}
void StudentNode::setLastName(string lastName) {
    this->lastName = lastName;
}

CourseNode* StudentNode::getHead() {
    return this->courseHead;
}

StudentNode* StudentNode::getNext() {
    return this->next;
}

StudentNode* StudentNode::getPrev() {
    return this->prev;
}

void StudentNode::setHead(CourseNode* head) {
    this->courseHead = head;
}

void StudentNode::setNext(StudentNode* next) {
    this->next = next;
}

void StudentNode::setPrev(StudentNode* prev) {
    this->prev = prev;
}

