#ifndef HW3_LAST_SUBSCRIBER_H
#define HW3_LAST_SUBSCRIBER_H
#include "LinkedList.h"
#include "CourseLinkedList.h"

using namespace std;

class Student
{
public:
    Student();

    const int getId() const;

    void setId(const int subscriberId);

    //hecks if the subscriber has a specific movie
    bool hasMovie(const int movieId);
    //shows subscriber info
    void showInfo();
    //shows the movies of the subscriber
    void showAllMovies();
    //shows a single movie of the subscriber
    void addSubs(int id);
    //void addTransaction(const int id);
    void addMovie(const int id);
    void removeMovie(const int id);
    void showTransactions();

    int subscriberId;
    LinkedList movies;
    CourseLinkedList transactions;
    void findMovie(const int movieId) const;
    Student* next;
};
#endif //HW3_LAST_SUBSCRIBER_H
