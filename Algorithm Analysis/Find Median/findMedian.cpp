#include <cstdlib>
#include <math.h>
#include "findMedian.h"

// ------- Functions for the first solution ---------- //
void swap( int &n1, int &n2 )
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
int FIND_MEDIAN_1( int input[], const int n)
{
    int maxIndex, maxValue;
    int count = 0;
    while(count < (n+1)/2)
    {
        maxIndex = count;
        maxValue = input[count];
        for( int j = count+1; j < n; j++ )
        {
            if( input[j] >= maxValue )
            {
                maxIndex = j;
                maxValue = input[j];
            }
        }
        swap( input[count], input[maxIndex] );
        count++;
    }
    return input[count-1];
}

// ------- Functions for the second solution ---------- //
int randomizedPartition( int input[], int p, int r )
{
    int index = rand() % (r-p+1) + p;
    swap(input[index], input[r]);
    int x = input[r];
    int i = p - 1;
    for( int j = p; j < r; j++ )
    {
        if( input[ j ] >= x )
        {
            i = i + 1;
            swap( input[i], input[j]);
        }
    }
    swap(input[i+1], input[r]);
    return i + 1;
}
void randomizedQuickSort(int input[], int p, int r )
{
    int q;
    if( p < r )
    {
        q = randomizedPartition( input, p, r );
        randomizedQuickSort( input, p, q - 1 );
        randomizedQuickSort( input, q + 1, r );
    }
}
int FIND_MEDIAN_2(int input[], const int n)
{
    randomizedQuickSort(input, 0, n - 1 );
    return input[(n-1)/2];
}

// ------- Functions for the third solution ---------- //
int partition( int input[], int a, int p, int r )
{
    int x = a, i = p - 1;
    for( int j = p; j < r; j++ )
    {
        if( input[ j ] == x )
        {
            swap( input[ j ], input[ r ] );
        }
        if( input[ j ] >= x )
        {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[ i + 1 ], input[ r ] );
    return i + 1;
}
void quickSort( int input[], int p, int r )
{
    int q;
    if( p < r )
    {
        q = partition( input, input[ r ], p, r );
        quickSort( input, p, q - 1 );
        quickSort( input, q + 1, r );
    }
}
int findMin( int n1, int n2 )
{
    if( n1 <= n2 )
        return n1;
    else
        return n2;
}
int select( int input[], int n, int k, int start, int end, int flag )
{
    if( n <= 5 )
    {
        quickSort( input, start, end );
        return input[ start + k - 1 ];
    }
    int i = start, numGroups = (int) ceil( ( double ) n / 5 ), numElements, j = 0;
    int *medians = new int[numGroups];
    while( i <= end )
    {
        numElements = findMin( 5, end - i + 1 );
        medians[( i - start ) / 5] = select( input, numElements, (int) ceil( ( double ) numElements / 2 ), i, i + numElements - 1, 1 );
        i = i + 5;
    }
    int M = select( medians, numGroups, (int) ceil( ( double ) numGroups / 2 ), 0, numGroups - 1, 1 );
    delete[] medians;
    if( flag == 1 )
        return M;
    int q = partition( input, M, start, end );
    int m = q - start + 1;
    if( k == m )
        return M;
    else if( k < m )
        return select( input, m - 1, k, start, q - 1, 0 );
    else
        return select( input, end - q, k - m, q + 1, end, 0 );
}
int FIND_MEDIAN_3( int input[], const int n)
{
    return select(input, n, (n+1)/2, 0, n - 1, 0 );
}

