#include <iostream>
using namespace std;

// traversel fo An Array
void display(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// Insertion in Array at specific index
// we have tale 4 parameters in this which are as follow : 
// 1-> array it self
// 2-> size of the array , which we have define in main() function
// 3-> Element: which element we have to insert in array
// 4-> Index is taken for to show at which index we have to insert new Element
// 5-> and finall we have took capacity to check wheather the array size is availaible or full.
int IndexInsertion(int arr[], int size, int element, int index, int capacity)
{

    // checking if size is not over the capacity of array
    if (size >= capacity)
    {
        return -1;
    }

    // insertion of the element in array
    for (int i = size - 1; i >= index; i--)
    {
        // shifting element to 1
        arr[i + 1] = arr[i];
    }
    cout << endl;
    // placin elemnet at given index
    arr[index] = element;

    return 1;
}

int main()
{

    int arr[100] = {2, 4, 6, 7, 9};
    int size = 5, index = 2, element = 5;
    // callin display function
    display(arr, size);

    // calling Insertion Function
    // as an argument we took Aarray, size of used array, element to enter in array,
    // index for where to enter in array, capacity of array for checking array has space or not
    IndexInsertion(arr, size, element, index, 100);
    //incresing size of the Array
    size += 1;
    display(arr, size);
    return 0;
}