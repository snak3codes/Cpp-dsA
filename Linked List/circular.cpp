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

    Node(int k, int d)
    {
        key = k;
        data = d;
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

    // 1. Check if Node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL) // No nodes in the list
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head); // Do-While makes sense to run the loop at least once (even when ptr is initially pointing to HEAD)
        }
        return temp;
    }

    // 2. Append a Node to the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Append another Node with a different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node Appended at first HEAD position" << endl;
            }
            else
            {
                Node *ptr = head;

                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                cout << "Node Appended Successfully" << endl;
            }
        }
    }

    // 3. Prepend Node to the list
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Prepend another Node with a different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node Prepended at first HEAD position" << endl;
            }
            else
            {
                Node *ptr = head;

                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                head = n;
                cout << "Node Prepended Successfully" << endl;
            }
        }
    }

    // 4. Insert a Node after a particular Node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with key value: " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value: " << n->key << ". Append another Node with a different key value" << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    n->next = head;
                    ptr->next = n;
                    cout << "Node Inserted at the END" << endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node Inserted in BETWEEN" << endl;
                }
            }
        }
    }

    // 5. Delete Node by unique key
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with key value: " << k << endl;
        }
        else
        {
            if (ptr == head)
            {
                if (head->next == head)
                {
                    head = NULL;
                    cout << "HEAD Node Unlinked. List is now Empty" << endl;
                }
                else
                {
                    Node *ptr1 = head;

                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Node Unliked with key value: " << k << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevPtr = head;
                Node *currPtr = head->next;

                while (currPtr != NULL)
                {
                    if (currPtr->key == k)
                    {
                        temp = currPtr;
                        currPtr = NULL; // To exit out of the while loop
                    }
                    else
                    {
                        prevPtr = prevPtr->next;
                        currPtr = currPtr->next;
                    }
                }
                prevPtr->next = temp->next;
                cout << "Node Unlinked with key value: " << k << endl;
            }
        }
    }

    // 6. Update Node by key
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data Updated Successfully" << endl;
        }
        else
        {
            cout << "No Node exists with key value: " << k << endl;
        }
    }

    // 7. Printing the Circular Singly Linked List
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in the Circular Singly Linked List" << endl;
        }
        else
        {
            cout << endl
                 << "HEAD address: " << head << endl;
            cout << "Circular Singly Linked List Values: " << endl;

            Node *temp = head;

            do
            {
                if (temp->next == head)
                {
                    cout << "(" << temp->key << ", " << temp->data << ", " << temp->next << ")";
                    break;
                }
                cout << "(" << temp->key << ", " << temp->data << ", " << temp->next << ") --> ";
                temp = temp->next;
            } while (temp != head);
        }
    }
};

// main function
int main()
{
    cout << "-- Circular Linked List --" << endl;

    CircularLinkedList CLL;
    int option, key1, k1, data1;

    do
    {
        cout << "\nWhat operation do you want to perform? Select Option Number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. printList()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;

        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            cout << "Bye!" << endl;

            break;

        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            CLL.appendNode(n1);

            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            CLL.prependNode(n1);

            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this new Node" << endl;
            cin >> k1;
            cout << "Enter key & data of the new Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            CLL.insertNodeAfter(k1, n1);

            break;

        case 4:
            cout << "Delete Node by Key Operation \nEnter key of the Node to be Deleted: ";
            cin >> k1;

            CLL.deleteNodeByKey(k1);

            break;

        case 5:
            cout << "Update Node by Key Operation \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;

            CLL.updateNodeByKey(key1, data1);

            break;

        case 6:
            CLL.printList();
            cout << endl;

            break;

        case 7:
            system("clear");

            break;

        default:
            cout << "Enter a Valid Option Number from 0 to 7!" << endl;

            break;
        }

    } while (option != 0);

    return 0;
} // end of main