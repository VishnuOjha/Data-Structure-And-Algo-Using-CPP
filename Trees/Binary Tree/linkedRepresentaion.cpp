#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *right;
    Node *left;

    Node()
    {

        data = 0;
        right = NULL;
        left = NULL;
    }

    Node(int val)
    {
        data = val;
    }
};

class LinkedRepresenatation
{

public:
    Node *head;

    LinkedRepresenatation()
    {

        head = NULL;
    }

    LinkedRepresenatation(Node *p)
    {

        head = p;
    }

    Node* createNode(int data)
    {
        Node * n = new Node();
        n->data = data;
        n->right = NULL;
        n->left = NULL;

        return n;
    }
};

int main()  
{
    // Creating object of the class LInkedRepresentation
    LinkedRepresenatation l;

    // creating a root Node
    Node* p = l.createNode(2);

    // creating a second Node
    Node* p1 = l.createNode(1);

    // creating a third Node
    Node* p2 = l.createNode(11);


    //Linking the nodes with children
    p->left = p1;
    p->right = p2;

    return 0;
}