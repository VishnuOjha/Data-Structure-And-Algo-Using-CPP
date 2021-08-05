#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

//case 1: Deleting the First node form linked List
struct Node *deleteTheFirstNode(struct Node *head)
{

    struct Node *ptr = head;
    head = head->next;
    // free the ptr from the heap memory location
    free(ptr);

    return head;
}

// Case 2: Deleting the Node At specific Index from Linked List
struct Node *deleteAtTheIndex(struct Node *head, int index)
{

    struct Node *ptr = head;
    struct Node *p = head->next;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);

    return head;
}

// Case 3: Deleting the Node at The Ending of The Linked List
struct Node *deleteAtTheEnd(struct Node *head)
{

    struct Node *ptr = head;
    struct Node *qtr = head->next;

    while (qtr->next != NULL)
    {
        ptr = ptr->next;
        qtr = qtr->next;
    }

    ptr->next = NULL;

    free(qtr);

    return head;
}

// Case 4: Deleting the Ndoe by Given Value from The index
struct Node *deletAtgivenValue(struct Node *head, int value)
{

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
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

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *five;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    five = (struct Node *)malloc(sizeof(struct Node));

    // linking the head node
    head->data = 5;
    head->next = second;

    //defining and linking second Node
    second->data = 7;
    second->next = third;

    //defining and linking third Node
    third->data = 11;
    third->next = fourth;

    //defining and linking fourth Node
    fourth->data = 15;
    fourth->next = five;
    //defining and linking five Node
    five->data = 18;
    five->next = NULL;

    cout << "linked List Before the deletion :" << endl;
    linkedListTraveesal(head);
    cout << endl;
    // head = deleteTheFirstNode(head);
    // head= deleteAtTheIndex(head,4);
    // head = deleteAtTheEnd(head);
    head = deletAtgivenValue(head, 11);
    cout << "Linked List After the deletion : " << endl;
    linkedListTraveesal(head);

    return 0;
}