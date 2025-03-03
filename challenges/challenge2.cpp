#include <iostream>
#include "cppUtil.h"
 
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    std::cout << "Given array is \n";
    printArray(arr, arr_size);
 
    return 0;
}