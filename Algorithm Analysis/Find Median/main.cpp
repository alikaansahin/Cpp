/**
*Ali Kaan SAHIN
*22002932
*CS201-3
*/
#include <iostream>
#include <chrono>
#include "findMedian.h"
using namespace std;

int main()
{
    cout<< "ENTER SIZE" <<endl;
    int n = 0;
    cin>> n;

    int* arr = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];

    for(int i = 0; i < n ; i++)
    {
        arr[i] = (rand()%2000) - 1000;
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    //ALGORITHM 1...

    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;

    startTime = std::chrono::system_clock::now();

    FIND_MEDIAN_1( arr, n );

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

    delete[] arr;

    //ALGORITHM 2...
    std::chrono::time_point< std::chrono::system_clock > startTime2;
    std::chrono::duration< double, milli > elapsedTime2;

    startTime2 = std::chrono::system_clock::now();

    FIND_MEDIAN_2( arr2, n );

    elapsedTime2 = std::chrono::system_clock::now() - startTime2;
    cout << "Execution took " << elapsedTime2.count() << " milliseconds." << endl;

    delete[] arr2;

    //ALGORITHM 3...
    std::chrono::time_point< std::chrono::system_clock > startTime3;
    std::chrono::duration< double, milli > elapsedTime3;

    startTime3 = std::chrono::system_clock::now();

    FIND_MEDIAN_3( arr3, n );

    elapsedTime3 = std::chrono::system_clock::now() - startTime3;
    cout << "Execution took " << elapsedTime3.count() << " milliseconds." << endl;

    delete[] arr3;
}
