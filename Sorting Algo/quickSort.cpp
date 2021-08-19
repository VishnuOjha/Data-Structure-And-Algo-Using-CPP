#include <iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int *arr, int low, int high)
{

    int partitionIndex; // index of pivot after partition

    if(low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // Sort leftsub array
        quickSort(arr, partitionIndex + 1, high); // Sort rightsub array
    }
}

int main()
{

    int arr[] = {1, 4, 8, 7, 6, 4, 2, 5, 55, 44, 98, 100, 21, 30, 10, 54, 74};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before Quick sort"<< endl;
    display(arr, size);
    cout << endl;
    cout << "After Quick sort" << endl;
    quickSort(arr, 0, size - 1);
    display(arr, size);

    return 0;
}