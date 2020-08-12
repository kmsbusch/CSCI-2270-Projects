#include "swap.h"
#include <iostream>
#include <fstream>
using namespace std;

// Function definitions
// Pass By Value
void swap(int n1, int n2) {
  int temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
}

// Pass By Pointer
void swap_by_pointers(int *n1, int *n2) {
  // TODO Complete this function
  int temp;
  temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

// Function to reverse the array through pointers
void reverse(int array[], int array_size)
{
    // pointer1 pointing at the beginning of the array
    int *pointer1 = array;

    // pointer2 pointing at end of the array
    int *pointer2 = array + array_size - 1;
    int *pointer3 = array + 1;
    int *pointer4 = array + 3;
    cout << *pointer1 << " " << *pointer2 << endl;
    // TODO Use the above swap function and update pointers to reverse your array
    while (pointer1 < pointer2) {
      swap_by_pointers(pointer1, pointer2);
      *pointer1++;
      *pointer2--;
    }
}
