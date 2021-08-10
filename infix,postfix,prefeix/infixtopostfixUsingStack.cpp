#include <iostream>
#include<string.h>
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

int stackTop(struct Stack *sp){

    return sp->arr[sp->top];
}

void display(struct Stack *ptr)
{

    for (int i = 0; i < ptr->size - 1; i++)
    {
        cout << ptr->arr[i] << endl;
    }
}

int precedence(char ch){
    if(ch == '*' || ch =='/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 1;
    }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
        return 1;
    }
    else{
        return 0;
    }
}


char * infixtopostfix(char * infix){

    struct Stack *sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char)); 
    int i = 0; // track infix traversal
    int j = 0; // track postfix addition

    while (infix[i] != '\0')
    {
       if(!isOperator(infix[i])){
           postfix[j] = infix[i];
           j++;
           i++;
       }

       else{

           if(precedence(infix[i] > precedence(stackTop(sp)))){
               push(sp,infix[i]);
               i++;
           }

           else{

               postfix[j] = pop(sp);
               j++;
           }
       }
    }

    while(!isEmpty(sp)){

        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char* exp ="x-y/z-k*d";
    cout<<"infix to postfix : "<<endl;
  printf("%s",infixtopostfix(exp))  ;
   

    return 0;
}