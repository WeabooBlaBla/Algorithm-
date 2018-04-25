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
void insertionSort(int array[], int size);
void selectionSort(int array[], int size);
void radixSort(stirng aBigNumber);
void bubbleSort(int array[], int size);
void mergeSort(int array[], int mid, int size);
void quickSort(int array[], int mid, int size);
void swap(int &a, int &b);
int main() {

    return 0;
}
void selectionSort(int array[], int size)
{
  for(int i=0; i<size-1; i++){
    min = i;
    for(int j = i+1; j < size; j++){
      if(a[min] > a[j]){
        min = j;
      }
    }
    swap(a[min],a[i]);
  }
}
void insertionSort(int array[], int size)
{
  for(int i=1; i < size -1; i++)
  {
    int key = array[i];
    int j=i-1;
    while(j>=0 && array[j] > key)
    {
      a[j+1] = a[j];
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
      if(a[j] > a[j+1]) swap(a[j],a[j+1]);
    }
  }
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
