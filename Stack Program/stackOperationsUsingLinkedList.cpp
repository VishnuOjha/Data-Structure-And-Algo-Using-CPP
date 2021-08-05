#include <iostream>
using namespace std;

struct Node
{

    int data;
    struct Node *next;
};

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
}

int pop(struct Node **top)
{

    if (isEmpty(*top))
    {
        cout << "Stack is udnerflow" << endl;
        return 1;
    }

    else
    {

        int x = (*top)->data;
        struct Node *ptr = *top;
        *top = (*top)->next;
        free(ptr);
        return x;
    }
}

void linkedListTraveesal(struct Node *ptr)
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

    struct Node *top = NULL;

    top = push(top, 5);
    top = push(top, 4);
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 1);
    linkedListTraveesal(top);
    cout << "After the POP function" << endl;
    int element = pop(&top);
    cout << "pop element is : " << element << endl;
    linkedListTraveesal(top);
    // top =

    return 0;
}