#include<iostream>
#include <algorithm>


using namespace std ;

int main()
{
    int arr[10] ;

    //fill array with random numbers
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i] = (rand() % 100) + 50;
    }


    //merge sort the array arr
    mergeSort(arr, 0, 9) ;






    
}