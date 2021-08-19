#include<iostream>
using namespace std;

void display(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}


int maximum(int *a , int n){

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(max<a[i]){
            max = a[i];
        }
    }
    return max;
}


void countSort(int *a, int n){

    int i,j;

    //find the maximum element in array
    int max = maximum(a,n);


    //create the new count array
    int *count = new int[max];

    //intialize all the count elements to 0
    for ( i = 0; i < n+1; i++)
    {
        count[i] = 0;
    }

    // increment the corresponding index in count array
    for ( i = 0; i < n; i++)
    {
        count[a[i]] =  count[a[i]] +1;
    }
    
    i = 0; //counter for the coynt array
    j = 0; //counter fot the a array


        // cpoying the elements from count array to A array
    while(i <= max){
        if(count[i]>0){
            a[j] = i;
            count[i] = count[i] -1;
            j++;
        }
        else{
            i++;
        }
    }
}


int main()
{

    // int arr[] = {1, 4, 8, 7, 6, 4, 2, 5, 55, 44, 98, 100, 21, 30, 10, 54, 74};
    int arr[] = {2, 5, 7, 6, 4, 22, 14, 21, 10};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before Count sort" << endl;
    display(arr, size);
    cout << endl;
    cout << "After Count sort" << endl;
    countSort(arr, size);
    display(arr, size);
    return 0;
}