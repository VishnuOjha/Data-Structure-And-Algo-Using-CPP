#include <iostream>
using namespace std;

// Defining the Linear Search
// As an arguments we took 3 parametres
// array it self, size of array and element to find in the array
int linearSearch(int a[], int size, int element)
{
    // calling a for loop
    for (int i = 0; i < size; i++)
    {
        // chacking if elements of array is equal to element we are searching
        if (a[i] == element)
        {
            // if element find then retunn the index
            return i;
        }
    }
// or else return -1 for not finding the element in array
    return -1;
}

int binarySearch(int a[], int size, int element)
{
    // Initializing 2 parametres for biary search
    int low, mid, high;
    
    //defining the values of low and high  
    low = 0;
    high = size-1;
    
    // initinalizing while and give condition if low <= high
    while (low <= high)
    {
        // finding the mid 
        mid = (low + high) / 2;

        for (int i = 0; i < size; i++)
        {   
            // cheking if mid index value is equal to an element or not
            if (a[mid] == element)
            {
                // if not them return the mid
                return mid;
            }
            // checking the value of mid is less than the value of element
            if (a[mid] < element)
            {
                // if yes then increase the low by mid+1
                low = mid + 1;
            }
            else
            {   // and if no then decrease the value of high by mid -1 
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 6, 8, 54, 62, 100};
    // for size of array we can do like this sizeofArray/sizeoInt
    int size = sizeof(arr) / sizeof(int);
    cout << sizeof(int) << " size of the int" << endl;
    int element = 62;
    // calling a Linear Search and determine the index of element
    // Linear search can be use for sorted and Unsorted array
    int searchIndex = linearSearch(arr, size, element);
    cout << "The element " << element << " found at " << searchIndex << " index"<<endl;

    cout<<"****************************************** BINARY SEARCH************************"<<endl;
    //Calling a Binary Search and Determining the Index of Element
    int sarchIndex2 = binarySearch(arr,size,element);
    cout << "The element " << element << " found at " << searchIndex << " index";

    return 0;
}