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

    Node *createNode(int data)
    {
        Node *n = new Node();
        n->data = data;
        n->right = NULL;
        n->left = NULL;

        return n;
    }

    void inOrderTraversal(Node *n)
    {

        if (n != NULL)
        {

            inOrderTraversal(n->left);
            cout << n->data << " ";
            inOrderTraversal(n->right);
        }
    }

    int isBST(Node *n)
    {

        static Node *prev = NULL;
        if (n != NULL)
        {
            if (!isBST(n->left))
            {
                return 0;
            }
            if (prev != NULL && n->data <= prev->data)
            {
                return 0;
            }

            prev = n;
            return isBST(n->right);
        }
        else
        {
            return 1;
        }
    }

    Node* search(Node *root, int key){
        if(root == NULL){
            return NULL;
        }
        if(root->data == key){
            return root;
        }
        else if(key < root->data){
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        }
    }
};

int main()
{ // Creating object of the class LInkedRepresentation
    LinkedRepresenatation l;

    // creating a root Node
    Node *p = l.createNode(5);

    // creating a second Node
    Node *p1 = l.createNode(3);

    // creating a third Node
    Node *p2 = l.createNode(6);
    Node *p3 = l.createNode(1);
    Node *p4 = l.createNode(4);

    //Linking the nodes with children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    l.inOrderTraversal(p);
    cout<<endl;

    Node * n = l.search(p, 6);
if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
}