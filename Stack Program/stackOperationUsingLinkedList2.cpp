#include <iostream>
using namespace std;

struct Node
{

    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty(struct Node *top)
{

    // struct Node* top = NULL;

    if (top == NULL)
    {

        cout << "Stak is underflow" << endl;
        return 1;
    }
    else
    {
        cout << "Satck is not underflow" << endl;
        return 0;
    }
}

int isFull(struct Node *top)
{

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int data)
{

    if (isFull(top))
    {

        cout << "Satck is Full" << endl;
        return top;
    }
    else
    {

        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
};

int pop(struct Node *tp)
{

    if (isEmpty(tp))
    {
        cout << "Stack is udnerflow" << endl;
        return 1;
    }

    else
    {

        int x = (tp)->data;
        struct Node *ptr = tp;
        top = (tp)->next;
        free(ptr);
        return x;
    }
}

int stackBottom(struct Node *top)
{

    struct Node*ptr = top;

    while (ptr->next != NULL)
    {
       ptr = ptr->next;
    }

    // ptr->data;
    return ptr->data;
}

int peek(int pos){

    struct Node *ptr= top;

    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }

    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }

}
    void linkedListTraveesal(struct Node * ptr)
    {

        // taking a while loop and iterate it until ptr==null
        while (ptr != NULL)
        {
            printf("Element : %d\n", ptr->data);
            ptr = ptr->next;
        }
    }

    int main()
    {

        top = push(top, 5);
        top = push(top, 4);
        top = push(top, 6);
        top = push(top, 7);
        top = push(top, 8);
        top = push(top, 1);
        linkedListTraveesal(top);
        cout << "After the POP function" << endl;
        pop(top);
        pop(top);
        pop(top);
        // cout << "pop element is : " << element << endl;
        linkedListTraveesal(top);

        cout << "Stack bottom Opertaion" << endl;
        int ele = stackBottom(top);
        cout<< "Value : "<<ele;        

        cout<<endl;
      int pos =   peek(1);
      cout<<"position :"<<pos;
        // top =

        return 0;
    }