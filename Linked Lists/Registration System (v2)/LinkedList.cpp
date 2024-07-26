//
// Created by anili on 13.12.2022.
//

#include "LinkedList.h"
LinkedList::LinkedList(){
    linkedListHead = NULL;
}

LinkedList::LinkedList(int id, int count) {
    linkedListHead = new Node(id, count);
    linkedListHead->nextNode = NULL;
}

void LinkedList::add(int id, int count) {
    if( linkedListHead == NULL){
        linkedListHead = new Node(id, count);
    }
    else{
        if( linkedListHead->id > id ){
            Node* temp = new Node(id, count);
            temp->nextNode = linkedListHead;
            linkedListHead = temp;
        }
        else if( linkedListHead->id < id){
            bool done = false;
            Node* add = new Node(id, count);
            for( Node* curr = linkedListHead; curr != NULL && !done; curr = curr->nextNode){
                if( curr->id < id){
                    if( curr->nextNode == NULL){
                        curr->nextNode = add;
                        done = true;
                    }
                    else{
                        if( curr->nextNode->id > id){
                            Node* temp = curr->nextNode;
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

bool LinkedList::remove(int id) {
    if( linkedListHead != NULL){
        Node* prev = linkedListHead;
        bool found = false;
        Node* curr = linkedListHead;

        for(; curr!= NULL && !found; prev = curr, curr = curr->nextNode ){
            if( curr->id == id){
                found = true;
                break;
            }
        }
        if( found ){
            if( curr == linkedListHead){
                linkedListHead = linkedListHead->nextNode;
            }
            else{
                prev->nextNode = curr->nextNode;
            }
            delete curr;
            return true;
        }
    }
    return false;
}

LinkedList::~LinkedList() {
    Node* current = linkedListHead;
    while( current != NULL ) {
        Node* next = current->nextNode;
        delete current;
        current = next;
    }
    linkedListHead = NULL;
}