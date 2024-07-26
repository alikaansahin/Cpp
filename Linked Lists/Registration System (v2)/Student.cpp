#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    subscriberId = 0;
    next = NULL;
}

void Student::addSubs(int id) {
    if( subscriberId > id ){
        Student* temp = new Student;
        temp->setId(id);
        temp->next = this;
    }
}

const int Student::getId() const
{
    return subscriberId;
}

void Student::setId(int id)
{
    this->subscriberId = id;
}


void Student::addMovie(const int movieId)
{
    transactions.add(movieId);
    movies.add(movieId, 0);
}


void Student::removeMovie(const int id){
    if(transactions.head != NULL){
        if (transactions.remove(id)){
            cout << "Movie " << id << " has been returned by subscriber " << subscriberId << "\n";
            movies.remove(id);
            return;
        }
    }
}

void Student::showAllMovies(){
    if (movies.linkedListHead != NULL)
    {
        for (Node *curr = movies.linkedListHead; curr != NULL; curr = curr->nextNode)
        {
            cout << "Movie " << curr->id;
            cout<<"has been rented by "<<subscriberId<<endl;
        }
    }
}

void Student::showTransactions() {
    cout << "Student " << subscriberId;
    if( transactions.head != NULL) {
        cout << " has rented the following movies: \n";
        for (CourseNode *temp = transactions.head; temp != NULL; temp = temp->nextNode) {
            string out = " not returned";
            if (temp->isReturned) { out = " returned"; }
            cout << temp->movieId << out << "\n";
        }
    }
    else{
        cout << " has not rented any movies\n";
    }

}

void Student::findMovie(const int movieId) const{
    if( transactions.head == NULL){
        return;
    }
    for(CourseNode* temp = transactions.head; temp != NULL; temp = temp->nextNode){
        if( temp->movieId == movieId){
            if( temp->isReturned )
                cout << subscriberId << " returned\n";
            else{
                cout << subscriberId << " not returned\n";
            }
        }
    }
}
/*
void Student::showMovie(int movieId)
{
    cout << "Rented by " << this->getId() << endl;
}


Student::CourseNode* Student::findMovie(const int movieId) const
{

    //iterating through the subscriber's movies
    for (CourseNode *tempPtr = transactionHead; tempPtr != NULL; tempPtr = tempPtr->nextTransactionNode)
    {
        if ( tempPtr->transaction.getMovieId() == movieId )
        {
            return tempPtr;
        }
    }
    return NULL;
}

 void Student::showInfo()
{

    cout <<"Student id: "<< this->getId() <<endl;

    if (this->transactionHead == NULL)
    {
        cout <<"Student "<< this->getId()<<" has no movies"<<endl;
    }
    else
    {
        cout <<"Student "<< this->getId() <<" has rented out the following books:"<<endl;


        for (CourseNode *iterPtr = transactionHead; iterPtr != NULL; iterPtr = iterPtr->nextTransactionNode)
        {
            cout << iterPtr->transaction.getMovieId() << endl;
        }
    }
}

 bool Student::hasMovie(const int movieId)
{

    return (findMovie(movieId) != NULL);
}

 */