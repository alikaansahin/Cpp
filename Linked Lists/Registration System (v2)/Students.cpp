#include "Students.h"
Students::Students() {
    head = NULL;
}

Students::~Students(){
    while( head != NULL){
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

void Students::addSub(int id) {
    if( head == NULL){
        head= new Student;
        head->setId(id);
        return;
    }
    if( head->getId() > id){
        Student* add = new Student;
        add->setId(id);
        add->next = head;
        head = add;
    }
    else if( head->getId() < id) {
        bool done = false;
        Student *add = new Student;
        add->setId(id);
        for (Student *curr = head; curr != NULL && !done; curr = curr->next) {
            if (curr->getId() < id) {
                if (curr->next == NULL) {
                    curr->next = add;
                    done = true;
                } else {
                    if (curr->next->getId() > id) {
                        Student *temp = curr->next;
                        curr->next = add;
                        add->next = temp;
                        done = true;
                    }
                }
            }
        }
    }
}

bool Students::removeSub(int id){
    if( head == NULL){
        return false;
    }
    Student* prev = head;
    Student* curr = head;
    bool found = false;
    for(;curr != NULL && !found; curr = curr->next){
        if(curr->getId() == id){
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
    }
    return false;
};
