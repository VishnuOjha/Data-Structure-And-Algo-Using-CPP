#include<iostream>
using namespace std;



int main()
{

    // Array using For Loop
    // int arr[5];

    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<"Enter the number : "1
    //     <<endl;
    //     cin>>arr[i];
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    int arr[] = {1, 2, 3, 34, 54};
    int i = 0;

    //Array Using While loop
    // while (i < 5)
    // {
    //     cout << arr[i] << " ";
    //     i++;
    // }

    //Array Using Do-While Loop
    do
    {
        cout << arr[i] << " ";
        i++;
    } while (i < 5);

    return 0;
}