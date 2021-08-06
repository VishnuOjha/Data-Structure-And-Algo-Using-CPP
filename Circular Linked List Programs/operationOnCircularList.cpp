#include <iostream>
using namespace std;

class Node
{

public:
    int key;
    int data;
    Node *next;

    Node()
    {

        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int d, int k)
    {
        data = d;
        key = k;
    }
};

class CircularLinkedList
{

public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    CircularLinkedList(Node *n)
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

        if (head == NULL)
        {
            return temp;
        }
        else
        {

            do
            {
                if (ptr->key == key)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);

            return temp;
        }
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
                n->next = head;
                cout << "Node is Appended as Head Node" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }

                ptr->next = n;
                n->next = ptr;
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
        else if (head == NULL)
        {

            head = n;
            n->next = head;
            cout << "Node is Appended as Head Node" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr != head)
            {
                ptr = ptr->next;
            }

            ptr->next = n;
            n->next = head;
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

                // appendin the Ndee at the End
                if (ptr->next == head)
                {

                    n->next = head;
                    ptr->next = n;
                    cout << "Node Instred at the End..." << endl;
                }

                //appendng node in between
                else
                {

                    n->next = ptr->next;
                    ptr->next = n;

                    cout << "Node is Instred..In Between" << endl;
                }
            }
        }
    }

    // case 5
    void deletNodeByKey(int key)
    {

        Node *ptr = nodeExits(key);

        if (ptr == NULL)
        {

            cout << "No NOde is existed withthe kay value..." << key;
        }

        else
        {

            if (ptr == head)
            {
                cout << "Singly Linked list is Empty" << endl;
            }
            else if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Head Node is unlinked  " << key << endl;
                }
                else
                {

                    Node *node = head;
                    while (node->next != head)
                    {
                        node = node->next;
                    }
                    node->next = head->next;
                    head = head->next;
                    cout << "Node Deleted..." << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *curptr = head->next;

                while (curptr != NULL)
                {
                    if (curptr->key == key)
                    {
                        temp = curptr;
                        curptr = NULL;
                    }
                    else
                    {

                        prevptr->next = prevptr->next;
                        curptr = curptr->next;
                    }
                }

                prevptr->next = temp->next;
                cout << "NOde unlinked with the key value..." << key << endl;
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
            cout<<"Head Adress"<<head<<endl;
            cout << endl
                 << "Doubly Linked List Values : " << endl;
            Node *temp = head;

           do
            {
                cout << "( key : " << temp->key<< ", data : " << temp->data << ") -->";
                temp = temp->next;
            } while (temp != head);
        }
    }
};

int main()
{

    CircularLinkedList c;
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
            c.appendNode(node);
            break;

        case 2:
            cout << "Enter the key and data to prePend the Node : " << endl;
            cin >> key;
            cin >> data;
            node->key = key;
            node->data = data;
            c.prePendNode(node);
            break;

        case 3:
            cout << "Enter the key of existing Node : " << endl;
            cin >> prevKey;
            cout << "Enter the key and data for new Node " << endl;
            cin >> key;
            cin >> data;
            node->key = key;
            node->data = data;
            c.insertNodeAfter(node, prevKey);
            break;

        case 4:
            cout << "Enter the key to Delete the Node : " << endl;
            cin >> prevKey;
            c.deletNodeByKey(prevKey);
            break;

        case 5:
            cout << "Enter the key and  NEW data to update the Node : " << endl;
            cin >> key;
            cin >> data;
            c.updateNodeByKey(key, data);
            break;

        case 6:
            cout << "Print the List : " << endl;
            c.traversal();
            break;

        case 7:
            cout << system("clear");
            break;

        default:
            cout << "Enter the proper Option" << endl;
        }
    } while (option != 0);

    return 0;
}