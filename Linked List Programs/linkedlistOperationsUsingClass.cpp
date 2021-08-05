#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    int key;
    Node *next;

    Node()
    {

        data = 0;
        key = 0;
        next = NULL;
    }

    Node(int k, int d)
    {

        data = d;
        key = k;
    }
};

class SingliLinkedList
{

public:
    Node *head;

    SingliLinkedList()
    {
        head = NULL;
    }

    SingliLinkedList(Node *n)
    {
        head = n;
    }

    Node *nodeExists(int key)
    {
        Node *temp = NULL;

        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        return ptr;
    }
};

int main()
{

    Node n1(1, 5);

    return 0;
}