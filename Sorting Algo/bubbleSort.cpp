#include <iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int *arr, int size)
{

    int temp;
    int isSorted = 0;
    for (int i = 0; i < size-1; i++) // for number of pass in bubble sort
    {   
        isSorted = 1;
        cout<<"Working on passes "<<i+1<<endl;
        for (int j = 0; j < size - 1 - i; j++) // forcaomparision in each passes
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted =0;
            }
        }

        if(isSorted){
            return;
        }
    }
}

int main()
{

    // int arr[] = {2, 5, 7, 6, 4, 22, 14, 21, 10};
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before the Bubble Sort" << endl;
    display(arr, size);
    cout << "After the Bubble Sort" << endl;
    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}