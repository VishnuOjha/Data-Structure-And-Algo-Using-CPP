#include <iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort(int *arr, int size)
{

    // iintialiing key and j variables
    int key, j;

    //loop of passes
    for (int i = 1; i <= size - 1; i++)
    {
        // set key to arr[i] and j = i-1
        key = arr[i];
        j = i - 1;

        // loop for each passes
        // chek j's value must be j>= 0 and arr[j] must be greater thean key
        while (j >= 0 && arr[j] > key)
        {
            // do arr[j+1] = arr[j] and j--
            arr[j + 1] = arr[j];
            j--;
        }
        // setting arr[j+1] = key
        arr[j + 1] = key;    
    }
    
}

int main()
{

    int arr[] = {2, 5, 7, 6, 4, 22, 14, 21, 10};
    // int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    cout<<endl;
    insertionSort(arr,size);
    display(arr,size);
    return 0;
}