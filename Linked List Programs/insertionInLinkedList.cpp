#include <iostream>
using namespace std;

struct Node
{

    int data;
    struct Node *next;
};

void linkedListTraveesal(struct Node *ptr)
{

    // taking a while loop and iterate it until ptr==null
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// // Case 1 : in this we are inserting a node at the beginning of linked list
// struct Node *insertAtHead(struct Node *head, int data)
// {

//     // creating and allocating memory to a pointer
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     // addressing ptr->next to head of the linked list
//     ptr->next = head;
//     // addressing ptr->data = data;
//     ptr->data = data;
//     return ptr;
// }

// Case 2: Insert Node at index in linked list
// it's take 3 parametres head,data,index
// struct Node * insertAtBetween(struct Node *head, int data, int index){

//     struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node *p = head;
//     int i=0;

//     while(i!=index-1){
//         p=p->next;
//         i++;
//     }

//     ptr->next = p->next;
//     p->next = ptr;
    
//     return head;
// }

// Case 3: inserting at End of the node
// struct Node * insertAtEnd(struct Node *head, int data){

//     struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node *p = head;

//     while(p->next!=NULL){
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = NULL;

//     return head;

// }

// Case 4: Insert after a Node 
struct Node * insertAfterNode(struct Node*head, struct Node* prevNode, int data){

    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;

}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // linking the head node
    head->data = 5;
    head->next = second;

    //defining and linking second Node
    second->data = 7;
    second->next = third;

    //defining and linking third Node
    third->data = 11;
    third->next = NULL;

    // calling the linkedtraversal function
    cout<<"Linked list before the Insertion :"<<endl;
    linkedListTraveesal(head);
    cout << endl;


    //calling insertion function
    // head = insertAtHead(head, 2);
    // head = insertAtBetween(head,4,2);
    // head = insertAtEnd(head,15);
    head = insertAfterNode(head,third,12);
    cout<<"Linked List after the insertion : "<<endl;
    linkedListTraveesal(head);

    return 0;
}