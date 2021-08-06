#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int size)
{

    int temp =-1;

    for(int i = 0; i<size; i++){

        if(arr[i] == n){

            cout<<"Element is found : "<<i<<endl;
            temp = 0;
            break;
        }

        
    }

    if(temp == -1){
            cout<<"No Element is found"<<endl;
        }

}

int main()
{

    int arr[] = {1, 56, 7, 9, 74, 2, 5, 21, 23};
    int n;
    int size = sizeof(arr) / sizeof(int);
    cout << "Enter the element you want to search : " << endl;
    cin >> n;

    linearSearch(arr, n,size);

    return 0;
}