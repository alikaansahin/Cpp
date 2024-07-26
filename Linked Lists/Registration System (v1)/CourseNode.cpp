//
// Created by ali20 on 20.05.2023.
//

#include "CourseNode.h"
CourseNode::CourseNode(int courseId, string courseName) {
    setId(courseId);
    setName(courseName);
    this->next = NULL;
}
CourseNode::~CourseNode(){
    next = NULL;
}

void CourseNode::setId(int courseId) {
    this->courseId = courseId;
}

int CourseNode::getId() {
    return courseId;
}

string CourseNode::getName() {
    return courseName;
}

void CourseNode::setName(string courseName) {
    this->courseName = courseName;
}

void CourseNode::setNext(CourseNode* next) {
    this->next = next;
}

CourseNode *CourseNode::getNext() {
    return next;
}


