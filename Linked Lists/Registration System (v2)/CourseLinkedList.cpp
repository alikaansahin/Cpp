#include "CourseLinkedList.h"
using namespace std;
CourseLinkedList::CourseLinkedList() {
    head = NULL;
}

CourseLinkedList::CourseLinkedList(int id, bool is) {
    head = new CourseNode(id, is);
}

void CourseLinkedList::add(int id) {
    if( head == NULL){
        head = new CourseNode(id, false);
    }
    else{
        if( head->movieId > id ){
            CourseNode* temp = new CourseNode(id, false);
            temp->nextNode = head;
            head = temp;
        }
        else if( head->movieId <= id){
            bool done = false;
            CourseNode* add = new CourseNode(id, false);
            for(CourseNode* curr = head; curr != NULL && !done; curr = curr->nextNode){
                if( curr->movieId <= id){
                    if( curr->nextNode == NULL){
                        curr->nextNode = add;
                        done = true;
                    }
                    else{
                        if( curr->nextNode->movieId > id){
                            CourseNode* temp = curr->nextNode;
                            curr->nextNode = add;
                            add->nextNode = temp;
                            done = true;
                        }
                    }
                }
            }
        }
    }
}

bool CourseLinkedList::remove(int id) {
    if( head != NULL){
        CourseNode* curr = head;

        for(; curr!= NULL; curr = curr->nextNode){
            if( curr->movieId == id) {
                if(!curr->isReturned){
                    curr->isReturned = true;
                    return true;
                }
            }
        }
    }
    return false;
}

CourseLinkedList::~CourseLinkedList(){
    CourseNode* current = head;
    while( current != NULL ) {
        CourseNode* next = current->nextNode;
        delete current;
        current = next;
    }
    head = NULL;
}
