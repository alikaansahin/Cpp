//
// Created by ali20 on 13.05.2023.
//
#ifndef REGISTRATION_SYSTEM_H
#define REGISTRATION_SYSTEM_H
#include "CourseNode.h"
#include "StudentNode.h"
using namespace std;

#include <string>

class RegistrationSystem {
public :
    RegistrationSystem();

    ~ RegistrationSystem();

    void addStudent(const int studentId, const string firstName, const string
    lastName);

    void deleteStudent(const int studentId);

    void addCourse(const int studentId, const int courseId, const string
    courseName);

    void withdrawCourse(const int studentId, const int courseId);

    void cancelCourse(const int courseId);

    void showStudent(const int studentId);

    void showCourse(const int courseId);

    void showAllStudents();

    StudentNode *studentHead;

    bool courseExists(const int courseId);

    StudentNode *findStudent(const int id);
};

#endif // REGISTRATION_SYSTEM_H
