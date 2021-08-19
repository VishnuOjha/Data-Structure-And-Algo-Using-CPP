#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSort(int *arr, int size)
{

    int indexOfMin, temp;

    for (int i = 0; i < size; i++)
    {
        indexOfMin = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {

                indexOfMin = j;
            }
        }
        // swap arr[i] & arr[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{

    int arr[] = {1, 4, 8, 7, 6, 4, 2};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    selectionSort(arr, size);
    cout << endl;
    printArray(arr, size);
    return 0;
}