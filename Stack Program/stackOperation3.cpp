#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{

    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{

    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int value)
{

    if (isFull(ptr))
    {

        cout << "Stack overflow can not push "<<value<<" in the stack"<<endl;
    }
    else
    {

        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct Stack *ptr){

    if(isEmpty(ptr)){
        cout<<"Stack is underflow"<<endl;
        return 1;
    }

    else{

        int x  = ptr->top;
        ptr->top = ptr->top -1;
        return x;


    }
}

void display(struct Stack *ptr){

    for (int i = 0; i < ptr->size-1; i++)
    {
        cout<<ptr->arr[i]<<endl;
    }
    

}

int main()
{

    // struct Stack s;
    // s.size =10;
    // s.top = -1;
    // s.ptr = (int *) malloc((s.size)*sizeof(int));

    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    cout << "Stack has been created Successfully " << endl;

    // pushing an element into Stack
    // sp->arr[0] = 1;
    // sp->top++;

    if (isEmpty(sp))
        cout << "Stack is empty"<<endl;

    else
        cout << "Stack is not empty" <<endl<<endl;

    // push(sp, 2);
    // push(sp, 3);
    // push(sp, 4);
    // push(sp, 5);
    // push(sp, 6);
    // push(sp, 7);
    // push(sp, 8);
    // push(sp, 9);
    // push(sp, 1);
    // push(sp, 2);
    // push(sp, 3);
    // push(sp, 4);
    // push(sp, 5);
    // push(sp, 6);
    // push(sp, 7);
    // push(sp, 8);
    // push(sp, 9);
    // push(sp, 2);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // display(sp);

  
   if (isEmpty(sp))
        cout << "Stack is empty"<<endl;

    else
        cout << "Stack is not empty" <<endl;

    return 0;
}