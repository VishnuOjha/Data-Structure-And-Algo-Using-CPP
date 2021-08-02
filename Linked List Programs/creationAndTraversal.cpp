#include<iostream>
using namespace std;

// defining the Node 
struct Node{
    int data;
    struct Node *next;
};

// defining the Linked List Traversal function
// It's take one argument which is struct Node *ptr, which is a pointer of struct Node
void linkedListTraveesal(struct Node *ptr){

    // taking a while loop and iterate it until ptr==null
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;

    }

}

int main(){

    // taking the nodes and creating it's objects
    struct Node *head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth; 

    // Dyanamic memory allocation of linked list by heap
    head = (struct  Node*) malloc(sizeof(struct Node));
    second = (struct  Node*) malloc(sizeof(struct Node));
    third = (struct  Node*) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // defining and linking head Node
    head-> data = 5;
    head-> next = second;

    //defining and linking second Node
    second->data=7;
    second->next = third;

    //defining and linking third Node
    third->data=11;
    third->next = fourth;

    //defining and linking fourth Node
    fourth->data=85;
    fourth->next = NULL;

    // calling the linkedtraversal function 
    linkedListTraveesal(head);

    return 0;

}