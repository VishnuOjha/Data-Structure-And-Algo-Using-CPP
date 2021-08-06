#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    char *arr;
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

void push(struct Stack *ptr, char value)
{

    if (isFull(ptr))
    {

        cout << "Stack overflow can not push " << value << " in the stack" << endl;
    }
    else
    {

        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct Stack *ptr)
{

    if (isEmpty(ptr))
    {
        cout << "Stack is underflow" << endl;
        return 1;
    }

    else
    {

        char x = ptr->top;
        ptr->top = ptr->top - 1;
        return x;
    }
}

int multiplParenthesisMatching(char* exp)
{

    struct Stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(struct Stack *ptr)
{

    for (int i = 0; i < ptr->size - 1; i++)
    {
        cout << ptr->arr[i] << endl;
    }
}

int main()
{

    char* exp ="[4-6]((8){(9-8)})";

    if (multiplParenthesisMatching(exp))
        cout << "paranetesis is matching..." << endl;

    else
        cout << "Parenthessis is Not matching.." << endl
             << endl;

    return 0;
}