//
// Created by ali20 on 13.05.2023.
//
#include "RegistrationSystem.h"
#include <iostream>

using namespace std;

RegistrationSystem::RegistrationSystem() {
    studentHead = NULL;
}

RegistrationSystem::~RegistrationSystem() {
    if (studentHead != NULL) {
        StudentNode *current = studentHead;
        while (current != NULL) {
            StudentNode *next = current->getNext();
            delete current;
            current = next;
        }
        studentHead = NULL;
    }
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
    if (studentHead == NULL) {
        studentHead = new StudentNode(studentId, firstName, lastName);
        cout << "Student " << studentId << " has been added" << endl;
    } else {
        StudentNode *prevStudent = NULL;
        StudentNode *currStudent = studentHead;
        while (currStudent != NULL && currStudent->getId() < studentId) {
            prevStudent = currStudent;
            currStudent = currStudent->getNext();
        }
        if (currStudent != NULL && currStudent->getId() == studentId) {
            cout << "Student " << studentId << " already exists" << endl;
            return;
        }
        StudentNode *newStudent = new StudentNode(studentId, firstName, lastName);
        newStudent->setNext(currStudent);
        newStudent->setPrev(prevStudent);
        if (prevStudent == NULL) {
            studentHead = newStudent;
        } else {
            prevStudent->setNext(newStudent);
        }
        if (currStudent != NULL) {
            currStudent->setPrev(newStudent);
        }
        cout << "Student " << studentId << " has been added" << endl;
    }
}

void RegistrationSystem::deleteStudent(const int studentId) {
    StudentNode *studentToDelete = findStudent(studentId);
    if (studentToDelete == NULL) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    //added outer if statement
    if(!(studentToDelete->getPrev() == NULL && studentToDelete->getNext() == NULL)) {
        if (studentToDelete->getPrev() == NULL) {
            studentHead = studentToDelete->getNext();
            //added
            studentToDelete->getNext()->setPrev(NULL);
            //added
        } else if (studentToDelete->getNext() == NULL) {
            studentToDelete->getPrev()->setNext(NULL);
        } else {
            studentToDelete->getPrev()->setNext(studentToDelete->getNext());
            studentToDelete->getNext()->setPrev(studentToDelete->getPrev());
        }
    }
    //added outer if statement
    //added outer else statement
    else{
        studentHead = NULL;
    }//added outer else statement
    cout << "Student " << studentId << " has been deleted" << endl;
    delete studentToDelete;

}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {

    StudentNode *student = studentHead;
    while (student != NULL) {
        CourseNode *currCourse = student->getHead();
        while (currCourse != NULL) {
            if (currCourse->getId() == courseId && currCourse->getName() != courseName) {
                cout << "Course " << courseId << " already exists with another name" << endl;
                return;
            }
            currCourse = currCourse->getNext();
        }
        student = student->getNext();
    }
    StudentNode *studentToAddCourse = findStudent(studentId);
    if (studentToAddCourse == NULL) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    if (studentToAddCourse->getHead() == NULL) {
        studentToAddCourse->setHead(new CourseNode(courseId, courseName));
        studentToAddCourse->getHead()->setNext(NULL);
        cout << "Course " << courseId << " has been added to student " << studentId << endl;
    } else {
        CourseNode *prevCourse = NULL;
        CourseNode *currCourse = studentToAddCourse->getHead();
        while (currCourse != NULL && currCourse->getId() < courseId) {
            prevCourse = currCourse;
            currCourse = currCourse->getNext();
        }
        if (currCourse != NULL && currCourse->getId() == courseId) {
            cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
            return;
        }
        CourseNode *newCourse = new CourseNode(courseId, courseName);
        newCourse->setNext(currCourse);
        if (prevCourse == NULL) {
            studentToAddCourse->setHead(newCourse);
        } else {
            prevCourse->setNext(newCourse);
        }

        cout << "Course " << courseId << " has been added to student " << studentId << endl;
    }
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
    StudentNode *studentToWithdraw = findStudent(studentId);
    if (studentToWithdraw == NULL) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    CourseNode *courseToBeWithdrawn;
    CourseNode *currCourse = studentToWithdraw->getHead();
    bool courseExist = false;

    while (currCourse != NULL) {
        if (courseId == currCourse->getId()) {
            courseToBeWithdrawn = currCourse;
            courseExist = true;
            break;
        }
        currCourse = currCourse->getNext();
    }

    if (!courseExist) {
        cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
        return;
    }

    if (courseToBeWithdrawn == studentToWithdraw->getHead()) {
        if (courseToBeWithdrawn->getNext() != NULL) {
            studentToWithdraw->setHead(courseToBeWithdrawn->getNext());
        } else {
            studentToWithdraw->setHead(NULL);
        }
    } else if (courseToBeWithdrawn->getNext() == NULL) {
        CourseNode *curr = studentToWithdraw->getHead();
        while (curr != NULL) {
            if (curr->getNext() == courseToBeWithdrawn) {
                curr->setNext(NULL);
            }
            curr = curr->getNext();
        }
    } else {
        CourseNode *curr = studentToWithdraw->getHead();
        while (curr != NULL) {
            if (curr->getNext() == courseToBeWithdrawn) {
                curr->setNext(courseToBeWithdrawn->getNext());
            }
            curr = curr->getNext();
        }
    }
    cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
    delete courseToBeWithdrawn;
}

void RegistrationSystem::cancelCourse(const int courseId) {

    StudentNode *currStudent = studentHead;
    bool courseTotallyExists = false;
    while (currStudent != NULL) {
        CourseNode *currCourse = currStudent->getHead();
        CourseNode *courseToBeCancelled;
        bool doesCourseExist = false;
        while (currCourse != NULL) {
            if (currCourse->getId() == courseId) {
                courseToBeCancelled = currCourse;
                doesCourseExist = true;
                courseTotallyExists = true;
                break;
            }
            currCourse = currCourse->getNext();
        }
        if (doesCourseExist) {
            if (courseToBeCancelled == currStudent->getHead()) {
                if (courseToBeCancelled->getNext() != NULL) {
                    currStudent->setHead( courseToBeCancelled->getNext());
                    delete courseToBeCancelled;
                } else {
                    currStudent->setHead(NULL);
                    delete courseToBeCancelled;
                }
            } else if (courseToBeCancelled->getNext() == NULL) {
                CourseNode *curr = currStudent->getHead();
                while (curr != NULL) {
                    if (curr->getNext() == courseToBeCancelled) {
                        curr->setNext(curr->getNext()->getNext());
                        delete courseToBeCancelled;
                    }
                    curr = curr->getNext();
                }
            } else {
                CourseNode *curr = currStudent->getHead();
                while (curr != NULL) {
                    if (curr->getNext() == courseToBeCancelled) {
                        curr->setNext(curr->getNext()->getNext());
                        delete courseToBeCancelled;
                    }
                    curr = curr->getNext();
                }
            }
        }
        currStudent = currStudent->getNext();
    }
    if (!courseTotallyExists) {
        cout << "Course " << courseId << " does not exist" << endl;
        return;
    }

    cout << "Course " << courseId << " has been cancelled" << endl;

}

void RegistrationSystem::showStudent(const int studentId) {
    StudentNode *studentToShow = findStudent(studentId);
    if (studentToShow == NULL) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    cout << "Student id First name Last name" << endl;
    cout << studentId << " " << studentToShow->getFirstName() << " " << studentToShow->getLastName() << endl;
    CourseNode *currCourse = studentToShow->getHead();
    if (currCourse != NULL) {
        cout << "Course id Course name" << endl;
    }
    while (currCourse != NULL) {
        cout << currCourse->getId() << " " << currCourse->getName() << endl;
        currCourse = currCourse->getNext();
    }
}

void RegistrationSystem::showCourse(const int courseId) {
    if (!courseExists(courseId)) {
        cout << "Course " << courseId << " does not exist" << endl;
        return;
    }
    CourseNode *course = NULL;
    StudentNode *student = studentHead;
    while (student != NULL) {
        CourseNode *currCourse = student->getHead();
        while (currCourse != NULL) {
            if (currCourse->getId() == courseId) {
                course = currCourse;
            }
            currCourse = currCourse->getNext();
        }
        student = student->getNext();
    }

    cout << "Course id Course name" << endl;
    cout << courseId << " " << course->getName() << endl;
    cout << "Student id First name Last name" << endl;
    StudentNode *studentToShow = studentHead;
    while (studentToShow != NULL) {
        CourseNode *currCourse = studentToShow->getHead();
        while (currCourse != NULL) {
            if (currCourse->getId() == courseId)
                cout << studentToShow->getId() << " " << studentToShow->getFirstName()
                     << " " << studentToShow->getLastName() << endl;
            currCourse = currCourse->getNext();
        }
        studentToShow = studentToShow->getNext();
    }
}

void RegistrationSystem::showAllStudents() {
    StudentNode *studentToShow = studentHead;
    if (studentToShow == NULL) {
        cout << "There are no students in the system" << endl;
        return;
    }
    cout << "Student id First name Last name" << endl;
    while (studentToShow != NULL) {
        cout << studentToShow->getId() << " " << studentToShow->getFirstName() << " " << studentToShow->getLastName() << endl;
        CourseNode *currCourse = studentToShow->getHead();
        if (currCourse != NULL) {
            cout << "Course id Course name" << endl;
        }
        while (currCourse != NULL) {
            cout << currCourse->getId() << " " << currCourse->getName() << endl;
            currCourse = currCourse->getNext();
        }
        studentToShow = studentToShow->getNext();
    }
}

StudentNode *RegistrationSystem::findStudent(const int id) {
    StudentNode *currStudent = studentHead;
    while (currStudent != NULL) {
        if (currStudent->getId() == id) {
            return currStudent;
        }
        currStudent = currStudent->getNext();
    }
    return NULL;
}

bool RegistrationSystem::courseExists(const int courseId) {

    bool isExist = false;
    StudentNode *student = studentHead;
    while (student != NULL) {
        CourseNode *currCourse = student->getHead();
        while (currCourse != NULL) {
            if (currCourse->getId() == courseId) {
                isExist = true;
            }
            currCourse = currCourse->getNext();
        }
        student = student->getNext();
    }
    return isExist;

}
