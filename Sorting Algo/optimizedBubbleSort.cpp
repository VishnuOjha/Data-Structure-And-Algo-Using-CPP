#include <iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void optimizeBubbleSort(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        int setFlag = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                setFlag = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        if (setFlag == false)
        {
            break;
        }
    }
}

int main()
{

    int arr[] = {2, 5, 7, 6, 4, 22, 14, 21, 10};
    // int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before the Bubble Sort" << endl;
    display(arr, size);
    cout << endl
         << "After the Bubble Sort" << endl;
    optimizeBubbleSort(arr, size);
    display(arr, size);

    return 0;
}