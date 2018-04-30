/*
 * File:   Algorithm.cpp
 * Author: Hung
 *
 * Created on April 25, 2018, 3:33 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 *
 */

void selectionSort(int array[], int size);
void bubbleSort(int array[], int size);
void swap(int &a, int &b);

void insertionSort(int array[], int size);

void mergeSort(int array[], int mid, int size);
void merge(int array[], int subLeft, int mid, int subRight);

void quickSort(int array[], int mid, int size);

void radixSort(string aBigNumber);

void printArray(int array[], int from, int to);
int main() {
    int array[] = {3,5,1,2,7,22,10,3};
    cout << "default array: " ;
    printArray(array,0,8);
    mergeSort(array,0,7);
    printArray(array,0,8);

    return 0;
}

void printArray(int array[], int from, int to)
{
  cout<<"{\t";
  for(int i=from; i<to;i++){
    cout<< array[i] << "\t";
  }
    cout << "}" << endl;
}

void selectionSort(int array[], int size)
{
  for(int i=0; i<size-1; i++){
    int min = i;
    for(int j = i+1; j < size; j++){
      if(array[min] > array[j]){
        min = j;
      }
    }
    swap(array[min],array[i]);
  }
}

void insertionSort(int array[], int size)
{
  for(int i=1; i < size; i++)
  {
    int key = array[i];
    int j=i-1;
    while(j>=0 && array[j] > key)
    {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
}
void bubbleSort(int array[], int size){
  //main idea: heaviest elem sink to the bottom
  for(int i = size - 2 ; i >= 0; i--)
  {
    for(int j = 0; j <= i ; j++)
    {
      if(array[j] > array[j+1]) swap(array[j],array[j+1]);
    }
  }
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void mergeSort(int array[], int left, int right) //recursion
{
  if(left<right)
  {
    int mid = (left+right) / 2;

    //divine
    mergeSort(array,left, mid);
    mergeSort(array,mid+1, right);

    //conquer
    merge(array, left, mid, right);
  }
}
void merge(int array[], int subLeft, int mid, int subRight)
{
  int *sortedArray;
  int sortedArraySize = subRight-subLeft+1;
  //cout<<sortedArraySize<<endl;
  sortedArray = new(nothrow) int[sortedArraySize];
  int sortedLeft = subLeft, sortedRight = mid+1, sortedIndex =0;

  while(sortedLeft <= mid && sortedRight <=subRight)
  {
    if(array[sortedLeft] <= array[sortedRight])
    {
      cout << array[sortedLeft] <<"<="<< array[sortedRight] << '\n';
      sortedArray[sortedIndex++] = array[sortedLeft++];
    }
    else
    {
      cout << array[sortedRight] <<"<="<<  array[sortedLeft]<< '\n';
      sortedArray[sortedIndex++] = array[sortedRight++];
    }
  }

  while(sortedLeft<=mid) sortedArray[sortedIndex++] = array[sortedLeft++];

  while(sortedRight<= subRight)
  {
  //  cout << sortedRight << '\n';
    sortedArray[sortedIndex++] = array[sortedRight++];
  }
  for(int i=0; i < sortedArraySize; i++)
  {
    array[subLeft+i] = sortedArray[i];
  }
  printArray(array, subLeft, sortedRight);
  cout  << '\n';
}
