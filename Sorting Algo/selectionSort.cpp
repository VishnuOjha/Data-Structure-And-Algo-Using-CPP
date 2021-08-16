#include <iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSort(int *arr, int size)
{

    int min;
    // for pass
    for (int i = 0; i < size; i++)
    {
        min = i;
        // for the each passes
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        //  cheack the value of min and swap
        if (min != 1)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}



int main(){

    int arr[] = {1,4,8,7,6,4,2};
    int size = sizeof(arr)/sizeof(int);

    cout<<"Before the Selection sort"<<endl;
    display(arr, size);
    cout<<endl;
    cout<<"After the selection Sort"<<endl;
    selectionSort(arr,size);
    display(arr, size);



}
