#include <iostream>
using namespace std;

class Node
{

public:
    int key;
    int data;
    Node *prevNode;
    Node *nextNode;

    Node()
    {
        key = 0;
        data = 0;
        prevNode = NULL;
        nextNode = NULL;
    }

    Node(int value, int k)
    {
        data = value;
        key = k;
    }
};

class DoublyLinkedList
{

public:
    // Pointer of class Node -> head
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    DoublyLinkedList(Node *n)
    {

        head = n;
    }

    // case 1 : Node exits or not uisng key
    // the reason to take return type Node* beacuse,
    // if the Node is exits in the list when we return it, it retrun type going to be Node*.
    Node *nodeExits(int key)
    {

        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                temp = ptr;
            }
            ptr = ptr->nextNode;
        }

        return temp;
    }

    //2 Append the data into the end of the list
    // here we are using pass by adress in the (Node* n)
    void appendNode(Node *n)
    {

        if (nodeExits(n->key) != NULL)
        {
            cout << "Node is already Exits" << n->key << endl;
        }
        else
        {

            if (head == NULL)
            {

                head = n;
                cout << "Node is Appended as Head Node" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->nextNode != NULL)
                {
                    ptr = ptr->nextNode;
                }

                ptr->nextNode = n;
                n->prevNode = ptr;
                cout << "Node is Appended" << endl;
            }
        }
    }
    // case 3 prepand the node in the list
    void prePendNode(Node *n)
    {

        if (nodeExits(n->key) != NULL)
        {
            cout << "Node is already Exits" << n->key << endl;
        }
        else if(head == NULL){
            head = n;
            cout<<"Nod eis appende as Head Node..."<<endl;
        }
        else
        {
            head->prevNode = n;
            n->nextNode = head;
            head = n;
            cout << "Node is added to the beginning" << endl;
        }
    }

    //case 4 Insert the Node in the List
    void insertNodeAfter(Node *n, int key)
    {

        Node *ptr = nodeExits(key);

        if (ptr == NULL)
        {
            cout << "No Node exits with the Key Value : " << key << endl;
        }
        else
        {

            if (nodeExits(n->key) != NULL)
            {
                cout << "Node Already Existed with the key value :" << key << endl;
            }
            else
            {

                cout << "Inserting the Node..." << endl;

                Node *newNode = ptr->nextNode;

                // appendin the Ndee at the End
                if (newNode == NULL)
                {

                    ptr->nextNode = n;
                    n->prevNode = ptr;
                    cout << "Node Instred at the End..." << endl;
                }

                //appendng node in between
                else
                {

                    n->nextNode = newNode;
                    newNode->prevNode = n;
                    n->prevNode = ptr;
                    ptr->nextNode = n;

                    cout << "Node is Instred.." << endl;
                }
            }
        }
    }

    // case 5
    void deletNodeByKey(int key)
    {

        Node *ptr = nodeExits(key);

        if (head == NULL)
        {
            cout << "Singly Linked list is Empty" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == key)
            {
                head = head->nextNode;
                cout << "Node is unlinked with key value of " << key << endl;
            }
            else
            {

                Node *prevNode = head->prevNode;
                Node *nextNodeNode = head->nextNode;

                if (nextNodeNode == NULL)
                {
                    prevNode->nextNode = NULL;
                    cout << "Node deleted at the end.." << endl;
                }
                else
                {

                    prevNode->nextNode = nextNodeNode;
                    nextNodeNode->prevNode = prevNode;
                    cout << "Node Deleted..." << endl;
                }
            }
        }
    }

    // case 6
    void updateNodeByKey(int prevKey, int data)
    {

        Node *ptr = nodeExits(prevKey);

        if (ptr != NULL)
        {

            ptr->data = data;
            cout << "Node data Updated.." << endl;
        }
        else
        {

            cout << "Node data  is not update sucsessfully..." << endl;
        }
    }
    // case 7:  Travesal
    void traversal()
    {

        if (head == NULL)
        {
            cout << "No node in the Doubly linked list" << endl;
        }

        else
        {

            cout << endl<< "Doubly Linked List Values : " << endl;
            Node *temp = head;

            while (temp != NULL)
            {
                cout << "(" << temp->key << temp->data << ") -->";
                temp = temp->nextNode;
            }
        }
    }
};

int main()
{

    DoublyLinkedList d;
    int option;
    int key, data, prevKey;

    do
    {
        cout << "\n Select an Opertaion to Performe : " << endl;
        cout << "1 : appendNode() " << endl;
        cout << "2 : prePandNode() " << endl;
        cout << "3 : insertNode() " << endl;
        cout << "4 : deletNode() " << endl;
        cout << "5 : updateNode() " << endl;
        cout << "6 : printList() " << endl;
        cout << "7 : Clear Screen " << endl;
        cin >> option;
        // dynamic memory allocatioin from heap using new keyword
        Node *node = new Node();
        switch (option)
        {

        case 0:
            break;

        case 1:
            cout << "Enter the key and data to Append the Node : " << endl;
            cin >> key;
            cin >> data;
            node->key = key;
            node->data = data;
            d.appendNode(node);
            break;

        case 2:
            cout << "Enter the key and data to prePend the Node : " << endl;
            cin >> key;
            cin >> data;
            node->key = key;
            node->data = data;
            d.prePendNode(node);
            break;

        case 3:
            cout << "Enter the key of existing Node : " << endl;
            cin >> prevKey;
            cout << "Enter the key and data for new Node " << endl;
            cin >> key;
            cin >> data;
            node->key = key;
            node->data = data;
            d.insertNodeAfter(node, prevKey);
            break;

        case 4:
            cout << "Enter the key to Delete the Node : " << endl;
            cin >> prevKey;
            d.deletNodeByKey(prevKey);
            break;

        case 5:
            cout << "Enter the key and  NEW data to update the Node : " << endl;
            cin >> key;
            cin >> data;
            d.updateNodeByKey(key, data);
            break;

        case 6:
            cout << "Print the List : " << endl;
            d.traversal();
            break;

        case 7:
            cout << system("clear");
            break;

        default:
            cout << "Enter the proper Option" << endl;
        }
    } while (option != 0);
}