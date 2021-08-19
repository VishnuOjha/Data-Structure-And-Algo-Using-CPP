#include <iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int *arr, int mid, int low, int high)
{

    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {

        if (arr[i] < arr[j])
        {

            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {

            B[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = arr[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = B[i];
    }
}

void mergeSort(int *arr, int low, int high)
{

    int mid;

    if (low < high)
    {

        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}

int main()
{

    // int arr[] = {1, 4, 8, 7, 6, 4, 2, 5, 55, 44, 98, 100, 21, 30, 10, 54, 74};
    int arr[] = {2, 5, 7, 6, 4, 22, 14, 21, 10};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before Merge sort" << endl;
    display(arr, size);
    cout << endl;
    cout << "After Merge sort" << endl;
    mergeSort(arr, 0, size-1);
    display(arr, size);
    return 0;
}