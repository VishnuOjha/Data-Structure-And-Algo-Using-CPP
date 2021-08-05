#include <iostream>
using namespace std;

// Creating a Node with some Values
// key-> it's a unique value of the Node so we can check that with same key new data can not insert while insertion of the node.
// data-> it's data of Node
// next-> it's referes to the next Node in the linked list
class Node
{

public:
    int data;
    int key;
    Node *next;

    // calling constructor
    Node()
    {

        data = 0;
        key = 0;
        next = NULL;
    }

    // calling parametrized constructor
    Node(int k, int d)
    {

        data = d;
        key = k;
    }
};

//creating a Singly linked list class
class SingliLinkedList
{

public:
    // creating a ponter of the Clas Node
    Node *head;

    // creating a constructor and initializin the head value to the null
    SingliLinkedList()
    {
        head = NULL;
    }

    // creating a parametrized constructor which initializing the head value to the n
    SingliLinkedList(Node *n)
    {
        head = n;
    }
    // 1st operation on the list
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

    //2nd Opertaion on the list
    // it will append the node at the end
    void appendNode(Node *n)
    {

        if (nodeExists(n->key) != NULL)
        {
            cout << "Node is already Exits" << n->key << endl;
        }
        else
        {

            if (head == NULL)
            {

                head = NULL;
                cout << "Node is Appended" << endl;
            }

            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = n;
            cout << "Node is Appende" << endl;
        }
    }

    // 3 at the node at the Beginning

    void prePandNode(Node *n)
    {

        if (nodeExists(n->key) != NULL)
        {
            cout << "Node is already Exits" << n->key << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node is added to the beginning" << endl;
        }
    }

    // 4 Insert a Node after a particular node
    void insertNodeAfter(Node *n, int k)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node is already Exits" << n->key << endl;
        }
        else
        {
            Node *ptr = nodeExists(k);
            if (ptr == NULL)
            {
                cout << "No node is existed with the key value" << endl;
            }
            else
            {

                if (nodeExists(n->key) != NULL)
                {
                    cout << "Node is already Exits" << n->key << endl;
                }
                else
                {

                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node is added " << endl;
                }
            }
        }
    }

    // 5 Delete Node by key

    void deletNodeByKey(int k)
    {

        if (head == NULL)
        {
            cout << "Singly Linked list is Empty" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node is unlinked with key value of " << k << endl;
            }
            else
            {

                Node *prevNode = head;
                Node *currentNode = head->next;
                Node *temp = NULL;

                while (currentNode != NULL)
                {
                    if (currentNode->key == k)
                    {
                        temp = currentNode;
                        currentNode = NULL;
                    }
                    else
                    {

                        prevNode = prevNode->next;
                        currentNode = currentNode->next;
                    }
                }
                if (temp != NULL)
                {
                    prevNode->next = currentNode->next;
                    cout << "Node is unlinked with key " << k << endl;
                }
                else
                {
                    cout << "Node dosen't exits with key " << k << endl;
                }
            }
        }
    }

    //6 updating node by given key
    void updateNodeByKey(int key, int data)
    {

        Node *ptr = nodeExists(key);

        if (ptr != NULL)
        {
            ptr->data = data;
            cout << "Node Data is Updated" << endl;
        }
        else
        {
            cout << "Node Dosen't exits with the key value" << endl;
        }
    }

    // 7 Travesal of the Linked List

    void traversal()
    {

        if (head == NULL)
        {
            cout << "No node in the singly linked list" << endl;
        }

        else
        {

            cout << endl
                 << "Singly Linked List Values : " << endl;
            Node *temp = head;

            while (temp != NULL)
            {
                cout << "(" << temp->key << temp->data << ") -->";
                temp = temp->next;
            }
        }
    }
};

int main()
{

    SingliLinkedList s;
    int option;
    int k1, key1, data;

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
            cin >> key1;
            cin >> data;
            node->key = key1;
            node->data = data;
            s.appendNode(node);
            break;

        case 2:
            cout << "Enter the key and data to prePend the Node : " << endl;
            cin >> key1;
            cin >> data;
            node->key = key1;
            node->data = data;
            s.prePandNode(node);
            break;

        case 3:
            cout << "Enter the key of existing Node : " << endl;
            cin >> k1;
            cout << "Enter the key and data for new Node " << endl;
            cin >> key1;
            cin >> data;
            node->key = key1;
            node->data = data;
            s.insertNodeAfter(node, k1);
            break;

        case 4:
            cout << "Enter the key to Delete the Node : " << endl;
            cin >> k1;
            s.deletNodeByKey(k1);
            break;

        case 5:
            cout << "Enter the key and  NEW data to update the Node : " << endl;
            cin >> key1;
            cin >> data;
            s.updateNodeByKey(key1, data);
            break;

        case 6:
            cout << "Print the List : " << endl;
            s.traversal();
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