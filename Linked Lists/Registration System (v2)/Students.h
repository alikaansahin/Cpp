#ifndef HW3_LAST_SUBSCRIBERS_H
#define HW3_LAST_SUBSCRIBERS_H
#include "Student.h"
#include "iostream"

class Students {
public:
    Students();
    ~Students();
    void addSub(int id);
    bool removeSub(int id);
    Student* head;
};
#endif //HW3_LAST_SUBSCRIBERS_H
