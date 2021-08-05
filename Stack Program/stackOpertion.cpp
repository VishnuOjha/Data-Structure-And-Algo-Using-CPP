#include <iostream>
#include <string.h>
using namespace std;

class Stack
{

    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;

        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {

        if (top == -1){

            cout<<"Stack is empty";    
            return true;
        }
            

        else
        {
            cout<<"Satck is Not empty";
            return false;
        }
            
    }

    bool isFull()
    {

        if (top == 4)
            return true;
        else
            return false;
    }

    int push(int value)
    {

        if (isFull())
        {

            cout << "Stack is overflowed" << endl;
            return 1;
        }
        else
        {   top++;
            arr[top] = value;
        }
        return 0;
    }

    int pop()
    {

        if (isEmpty())
        {
            cout << "Stack is underflow" << endl;
            return 1;
        }
        else
        {

            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count()
    {

        return (top + 1);
    }

    int peek(int pos)
    {

        if (isEmpty())
        {
            cout << "stack is emepty" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void change(int pos, int value)
    {

        arr[pos] = value;
        cout << "The Value at Position " << arr[pos] << " is " << value;
    }

    void display()
    {

        cout << "All the Value in stack : " << endl;

        for (int i = 0; i <5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Stack s;
    int option, pos, value;

    do
    {   cout<<endl<<endl;
        cout << "Enter the value to perform Any opertaion : " << endl;
        cout << "1 : push()" << endl;
        cout << "2 : pop()" << endl;
        cout << "3 : peek()" << endl;
        cout << "4 : change()" << endl;
        cout << "5 : count()" << endl;
        cout << "6 : display()" << endl;
        cout << "7 : isFull()" << endl;
        cout << "8 : isEmpty()" << endl;

        cin >> option;
        switch (option)
        {

        case 1:
            cout << "Enter the value to push into Stack : " << endl;
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Perfom the pop into Stack : " << endl;
            s.pop();
            break;

        case 3:
            cout << "enter position to peek the value : " << endl;
            cin >> pos;
            cout<<s.peek(pos);
            break;

        case 7:
            cout << "Performe isEmpty Operation :  : " << endl;
            cout<<s.isEmpty();
            break;

        case 8:
            cout << "Performe the isFull Opertaion : " << endl;
            cout<<s.isFull();
            break;

        case 4:
            cout << "Enter the value and POsition  : " << endl;
            cin >> value >> pos;
            s.change(pos, value);
            break;

        case 5:
            cout << "Count the Stack value : " << endl;
            cout<<s.count();
            break;

        case 6:
            cout << "Display the value of Stcak : " << endl;
            s.display(); 
			break;
        }

    } while (option != 0);

    return 0;
}