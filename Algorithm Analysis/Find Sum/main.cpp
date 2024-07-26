/**
*Ali Kaan SAHIN
*The algorithms’ goal is finding the maximum sequence of sum
*of randomly sorted array.
*/
#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
//
// Created by ali20 on 1.05.2023.
//

int maxSubSum1( int a[], int size) {
    int maxSum = 0;
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++) {
            int thisSum = 0;

            for (int k = i; k <= j; k++)
                thisSum += a[k];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    return maxSum;
}

int maxSubSum2(int a[], int size) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        int thisSum = 0;
        for (int j = i; j < size; j++) {
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

int max3(int a, int b, int c){
    if(a > b && a > c)
        return a;
    if(b > a && b > c)
        return b;
    if(c > a && c > b)
        return c;
}
int maxSumRec(int a[], int left, int right) {
    if(left == right) // base
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    int center = ( left + right ) / 2;
    int maxLeftSum = maxSumRec( a, left, center);
    int maxRightSum = maxSumRec( a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >= left; i--)
    {
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for(int j = center + 1; j <= right; j++)
    {
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3( maxLeftSum, maxRightSum,
                 maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSum3(int a[], int size) {
    return maxSumRec(a, 0, size - 1);
}

int maxSubSum4( int a[], int size) {
    int maxSum = 0, thisSum = 0;

    for (int j = 0; j < size; j++) {
        thisSum += a[j];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int main()
{
    cout<< "ENTER SIZE" <<endl;
    int n = 0;
    cin >> n;

    int* arr = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    int* arr4 = new int[n];

    for(int i = 0; i < n ; i++)
    {
        arr[i] = (rand()%2000) - 1000;
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }

    //ALGORITHM 1...

    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;

    startTime = std::chrono::system_clock::now();

    maxSubSum4( arr, n );//n

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

    delete[] arr;

    //ALGORITHM 2...
    std::chrono::time_point< std::chrono::system_clock > startTime2;
    std::chrono::duration< double, milli > elapsedTime2;

    startTime2 = std::chrono::system_clock::now();

    maxSubSum3( arr2, n );//nlogn

    elapsedTime2 = std::chrono::system_clock::now() - startTime2;
    cout << "Execution took " << elapsedTime2.count() << " milliseconds." << endl;

    delete[] arr2;

    //ALGORITHM 3...
    std::chrono::time_point< std::chrono::system_clock > startTime3;
    std::chrono::duration< double, milli > elapsedTime3;

    startTime3 = std::chrono::system_clock::now();

    maxSubSum2( arr3 , n );//n^2

    elapsedTime3 = std::chrono::system_clock::now() - startTime3;
    cout << "Execution took " << elapsedTime3.count() << " milliseconds." << endl;

    delete[] arr3;
    //ALGORITHM 4...
    std::chrono::time_point< std::chrono::system_clock > startTime4;
    std::chrono::duration< double, milli > elapsedTime4;

    startTime4 = std::chrono::system_clock::now();

    maxSubSum1( arr4, n );//n^3

    elapsedTime4 = std::chrono::system_clock::now() - startTime4;
    cout << "Execution took " << elapsedTime4.count() << " milliseconds." << endl;

    delete[] arr4;
}