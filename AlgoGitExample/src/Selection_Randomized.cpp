/*
 * Selection_Randomized.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: RAM
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArr(int arr[], int p, int n)
{
    cout << "Array : " << endl;
    for(int i=0; i<n; ++i)
    {
        cout << arr[p+i] << " ";
    }
    cout << endl;
}

void swapIdxs(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int getRandomPivotIdx(int p, int q)
{
    srand((unsigned)time(0));
    int pivotIdx = rand() % (q-p) + p;
    return pivotIdx;
}

int partition(int arr[], int p, int q)
{
    int pivotIdx = getRandomPivotIdx(p, q);
    //cout << "pivot index : " << pivotIdx << endl;;
    swapIdxs(arr, p, pivotIdx);
    int pivot = arr[p];
    //cout << "pivot element : " << pivot << endl;
    int less = p;
    for(int more=p+1; more<=q; ++more)
    {
        if(arr[more] <= pivot)
        {
            swapIdxs(arr, less+1, more);
            less++;
        }
    }
    swapIdxs(arr, p, less);
    return less;
}

int __selection_rand(int arr[], int p, int q, int rank)
{
    if (p == q)
    {
        return arr[p];
    }

    int pivotPos = partition(arr, p, q);
    //cout << endl << "pivot element : " << arr[pivotPos] << " start idx : " << p << " :: end idx : " << q << endl;
    //printArr(arr, p, (q-p+1));
    int currRank = pivotPos - p + 1;

    if (rank == currRank)
    {
        return arr[pivotPos];
    }
    else if (rank < currRank)
    {
        //cout << "left half upto : " << (pivotPos-1) << " :: rank : " << rank << endl;
        return __selection_rand(arr, p, pivotPos-1, rank);
    }
    else
    {
        //cout << "right half from : " << (pivotPos+1) << " :: rank : " << (rank-currRank) << endl;
        return __selection_rand(arr, pivotPos+1, q, rank-currRank);
    }

    return 0;
}

int selection_rand(int arr[], int n, int rank)
{
    if(rank < 1 || rank > n)
        return -1;
    return __selection_rand(arr, 0, n-1, rank);
}

int main()
{
    int arr[] = {5, 3, 12, 7, 19, 8, 13, 6, 1, 2, 15, 4, 17, 18, 10, 16, 9, 14, 11, 20};
    int rank;
    cout << "Enter rank to find :" << endl;
    cin >> rank;
    int elem = selection_rand(arr, (sizeof(arr) / sizeof(arr[0])), rank);
    cout << "Element at rank : " << rank << " : " << elem << endl;
    //printArr(arr, 0, (sizeof(arr) / sizeof(arr[0])));
}

