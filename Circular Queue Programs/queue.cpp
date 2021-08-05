#include <iostream>
using namespace std;

class CQueue
{

    private :
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    CQueue()
    {
        itemCount = 0;
        front = rear = -1;
    
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    void display()
    {

        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }

    bool isEmpty()
    {

        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {

        if ((rear+1)%5 == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int equeue(int value)
    {

        if (isFull())
        {
            return 0;
        }

        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear = (rear + 1)%5;
            arr[rear] = value;
        }

        itemCount++;
    }

    int dequeue()
    {

        int x = 0;

        if (isEmpty())
        {
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
            return x;
        }
        else
        {
             x = arr[front];
            arr[front] = 0;
            front = (front+1)%5;
            return x;
        }

        itemCount --;
    }
};

int main()
{

    CQueue q;
  
    q.equeue(6);
    q.equeue(4);
    q.equeue(2);
    q.equeue(3);
    q.display();
    cout<<endl;
    q.dequeue();
     q.dequeue();
      q.dequeue();
       q.dequeue();
        q.dequeue();
    q.display();


    return 0;
}