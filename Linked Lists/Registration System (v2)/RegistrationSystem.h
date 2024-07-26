#ifndef HW3_LAST_MOVIERENTALSYSTEM_H
#define HW3_LAST_MOVIERENTALSYSTEM_H

#include "Students.h"
#include "LinkedList.h"
#include "CourseLinkedList.h"

using namespace std;
class RegistrationSystem {
public :
    RegistrationSystem ();
    ~ RegistrationSystem ();
    void addStudent ( const int studentId , const string firstName , const string
    lastName );
    void deleteStudent ( const int studentId );
    void addCourse ( const int studentId , const int courseId , const string
    courseName );
    void withdrawCourse ( const int studentId , const int courseId );
    void cancelCourse ( const int courseId );
    void showStudent ( const int studentId );
    void showCourse ( const int courseId );
    void showAllStudents ();
};
private:
    Students subscriberHead;
    LinkedList movieHead;
    int subCount;

    Student* findSubscriber(const int subscriberId) const;

    //MovieNode* findMovie(const int movieId) const;

    //SubscriberNode* findRented(const int movieId) const;

    //bool internalReturn(SubscriberNode* subscriberNode, const int movieId );

    bool internalDeleteMovie(const int movieId);
};
#endif //HW3_LAST_MOVIERENTALSYSTEM_H
