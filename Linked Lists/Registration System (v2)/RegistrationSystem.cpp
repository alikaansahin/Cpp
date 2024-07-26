#include <iostream>
#include <fstream>
#include <string>
#include "RegistrationSystem.h"
using namespace std;


RegistrationSystem::RegistrationSystem(const string movieInfoFileName, const string subscriberInfoFileName)
{
    subCount = 0;
    //Declare variables
    int movieCount;
    int subscriberCount;
    int movieId;
    int copies;
    int subscriberId;
    ifstream movieDoc;
    ifstream subsDoc;
    movieDoc.open( movieInfoFileName.c_str(), ios_base::in );
    subsDoc.open( subscriberInfoFileName.c_str(), ios_base::in );

    if(movieDoc.is_open()){
        movieDoc >> movieCount;
        while ( movieDoc.eof() == false )
        {
            movieDoc >> movieId;
            movieDoc >> copies;
            movieHead.add( movieId, copies);
        }
    }
    else{
        cout<<"Input file "<< movieInfoFileName <<" does not exist"<<endl;
        return;
    }
    if(subsDoc.is_open())
    {
        subsDoc >> subscriberCount;
        while ( subsDoc.eof() == false )
        {
            subsDoc >> subscriberId;
            subscriberHead.addSub(subscriberId);
            subCount++;
        }
    }
    else
    {
        cout<<"Input file "<< subscriberInfoFileName <<" does not exist"<<endl;
    }

    if(subsDoc.is_open() && movieDoc.is_open())
    {

        cout << subscriberCount << " subscribers and "<< movieCount<<" movies have been loaded"<< endl;
    }

    movieDoc.close();
    subsDoc.close();
}


RegistrationSystem::~RegistrationSystem()
{
    delete movieHead.linkedListHead;
    delete subscriberHead.head;
}
void RegistrationSystem::removeMovie(const int movieId ){
    bool isExist = false;
       bool notReturned = false;
       for (Node *iterPtr = movieHead.linkedListHead; iterPtr->nextNode != NULL; iterPtr = iterPtr->nextNode)
       {
           if ( iterPtr->id == movieId )
           {
               isExist = true;
           }
       }
       for (Students *iterPtr = subscriberHead; iterPtr->nextSubscriberNode != NULL; iterPtr = iterPtr->nextSubscriberNode)
       {
           for (CourseNode *transactionPtr = iterPtr->subscriber.transactionHead; iterPtr->nextTransactionNode != NULL; iterPtr = iterPtr->nextTransacitonNode)
           {
               if ( iterPtr->transaction.getMovieId() == movieId && iterPtr->transaction.getIsReturned() == false)
               {
                   notReturned = true;
               }
           }
       }
       if(!isExist)
       {
           cout << "Movie " << movieId << " does not exist." <<endl;
       }
       if(notReturned)
       {
           cout << "Movie " << movieId << " cannot be removed -- at least one copy has not been returned" << endl;
       }

       if(movieHead != NULL && isExist && !notReturned)
       {
           if (movieId == 0 || movieHead->movie.getId() == movieId )
           {
               Node *tempPtr = movieHead->nextNode;
               delete movieHead;
               movieHead = tempPtr;
               cout<< "Movie " << movieId << " has been removed" <<endl;
               return;
           }
           //iterating through the movies
           for (Node *iterPtr = movieHead; iterPtr->nextMovieNode != NULL; iterPtr = iterPtr->nextMovieNode)
           {
               if ( iterPtr->nextMovieNode->movie.getId() == movieId )
               {
                   Node *tempPtr = iterPtr->nextMovieNode->nextMovieNode;
                   delete iterPtr->nextMovieNode;
                   iterPtr->nextMovieNode = tempPtr;
                   cout<< "Movie " << movieId << " has been removed" <<endl;
                   return;
               }
           }
       }
}

void RegistrationSystem::addMovie(const int movieId, const int numCopies ){
    bool alreadyExists = false;
    for (Node *iterPtr = movieHead.linkedListHead; iterPtr->nextNode != NULL; iterPtr = iterPtr->nextNode)
    {
        if ( iterPtr->id == movieId )
        {
            alreadyExists = true;
        }
    }
    if(alreadyExists)
    {
        cout << "Movie" << movieId << "already exists";
        return;
    }
    else
    {
        movieHead.add(movieId,numCopies);
        cout << "Movie " << movieId << " has been added";
    }
}
void RegistrationSystem::removeSubscriber(const int subscriberId )
{
    if( subscriberHead.removeSub(subscriberId)){
        subCount--;
    }
}
void RegistrationSystem::addSubscriber(const int subscriberId )
{
    subscriberHead.addSub(subscriberId);
    subCount++;
}

void RegistrationSystem::rentMovie(const int subscriberId, const int movieId ){
    bool rentable = false;
    bool found = false;
    for(Node* temp = movieHead.linkedListHead;temp!= NULL && !found; temp = temp->nextNode){
        if( temp->id == movieId){
            found = true;
            if( temp->count > 1){
                temp->count = temp->count--;
                rentable = true;
            }
            else
                rentable = false;
        }
    }
    if( rentable ){
        Student* temp = findSubscriber(subscriberId);
        if( temp != NULL){
            temp->addMovie(movieId);
        }
    }
}//ToDo
void RegistrationSystem::returnMovie(const int subscriberId, const int movieId ){
    Student* temp = findSubscriber(subscriberId);
    if( temp != NULL){
        temp->removeMovie(movieId);
    }
}

Student* RegistrationSystem::findSubscriber(const int subscriberId) const{
    for(Student* temp = subscriberHead.head; temp != NULL; temp = temp->next){
        if(temp->getId() == subscriberId){
            return temp;
        }
    }
    return NULL;
}

void RegistrationSystem::showMoviesRentedBy(const int subscriberId ) const{
    Student* temp;
    temp = findSubscriber(subscriberId);
    if( temp != NULL){
        temp->showTransactions();
    }
    else{
        cout << "Student " << subscriberId << " does not exist\n";
    }
}

void RegistrationSystem::showSubscribersWhoRentedMovie(const int movieId ) const{
    cout << "Movie " << movieId << " has been rented by the following subscribers:\n";
    for(Student* temp = subscriberHead.head; temp != NULL; temp = temp->next){
        temp->findMovie(movieId);
    }
}

void RegistrationSystem::showAllMovies() const{
    Node* movie = movieHead.linkedListHead;
    cout << "Movies in the movie rental system:" << endl;
    while(movie != NULL)
    {
        cout << movie->id << " " << movie->count << endl;
        movie = movie->nextNode;
    }
}

void RegistrationSystem::showAllSubscribers() const{
    Student* sub = subscriberHead.head;
    cout << "Students in the movie rental system:" << endl;
    while(sub != NULL)
    {
        cout << sub->getId() << endl;
        sub = sub->next;
    }
}

