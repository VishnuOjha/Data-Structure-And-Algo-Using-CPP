#include<iostream>
using namespace std;


void display(int arr[], int size){

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<< " ";
    }
    
}

// Deletion of Element in array
// so as parameter we took array,size of array and index,
// why we took index beacuse we have to tell,
// which number of element in index we want to delete
void IndDeletion(int arr[],int size, int ind){

    // in the for loop we start from index and wil gose up to size-1. 
    for (int i = ind; i < size-1; i++)
    {
        // inside the array we just chnage the value from one index to another. like 2 = 3, 3=4
        arr[i] = arr[i+1];
    }
    
    cout<<endl;

}

int main(){

    int arr[] = {7,9,5,4,2};
    int index = 0, size=5;
    display(arr,size);
    // calling deletion function for array
    IndDeletion(arr,size,index);
    // decrementig size of array to 1
    size -= 1;
    display(arr,size);

    return 0;
}