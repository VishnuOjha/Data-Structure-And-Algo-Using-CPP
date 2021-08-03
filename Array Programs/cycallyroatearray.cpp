#include<iostream>
using namespace std;



//defining the function it's takes two parameters
// array and size of array
void cycallyRoate(int arr[], int size){

    // first create temp and store the last element of array  
    int temp = arr[size-1];
    cout<<arr[size-1]<<endl;

    // intializing for loop and passing arguments
    // first it's starts form size-1 and go upto until array index comes to 0 and we decreaseing i--
    for (int i = size-1; i >0 ; i--)
    {
            // storing at index the index-1 elemenst value
           arr[i] = arr[i-1];
          
    }
    // setting up 0 index value to temp
     arr[0] = temp;
}

void display(int arr[],int size){

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){

    int arr[] = {1,5,4,6,3,8,4};
    int size =sizeof(arr)/sizeof(int);
   
    //calling function
    cycallyRoate(arr,size); 
    display(arr,size);

    return 0;

}