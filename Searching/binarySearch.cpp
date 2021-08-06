#include <iostream>
using namespace std;

int binarySearch(int arr[], int num, int size)
{

    int mid;
    int high = size - 1;
    int low = 0;

    while (low <= high)

    {
        mid = (low + high) / 2;
        for (int i = 0; i < size; i++)
        {
            if (arr[mid] == num)
            {
                return mid;
            }
            else if (arr[mid] < num)
            {

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{

    int arr[] = {1, 8, 15, 17, 35, 48, 66, 100};
    int size = sizeof(arr) / sizeof(int);
    int num = 17;
    cout << "Running Binary Search...." << endl;
    int ele = binarySearch(arr, num, size);
    cout<<ele;
    return 0;
}