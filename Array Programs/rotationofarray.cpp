#include<iostream>
using namespace std;


void leftrotatebyOne(int arr[],int size){

    int temp = arr[0],i;
    for (i = 0; i < size-1; i++){
        arr[i] = arr[i+1];}

        
    arr[size-1] = temp;
      
      
}
void leftRotate(int arr[], int size, int index){

    for (int i = 0; i < index; i++)
    {
        leftrotatebyOne(arr,size);
    }
    
}

void display(int arr[],int size){

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
    


int main(){

int arr[]={1, 2, 3, 4, 5, 6, 7};
int size = sizeof(arr)/sizeof(arr[0]);

 leftRotate(arr,size,4);
 display(arr,size);


    return 0;
}