#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *ptr;
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



int main()
{

    // struct Stack s;
    // s.size =10;
    // s.top = -1;
    // s.ptr = (int *) malloc((s.size)*sizeof(int));

    struct Stack *s;
    s->size = 10;
    s->top = -1;
    s->ptr = (int *)malloc(s->size * sizeof(int));

    // pushing an element into Stack
    // s->ptr[0] = 1;
    // s->top++;

    if (isEmpty(s))
        cout << "Stack is empty";

    else
        cout << "Stack is not empty";


    return 0;
}