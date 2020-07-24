#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    // 1. Check if node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL; //  Makes sure we can always return (either desired pointer or NULL)
        Node *ptr = head;  // Pointer to head

        while (ptr != NULL) // Traversing
        {
            if (ptr->key == k) // If ptr points to a Node with key 'k'
            {
                temp = ptr; // Make temp also point to that Node
            }
            ptr = ptr->next; // Advance ptr in the DLL
        }

        return temp;
    }

    // 2. Append a Node to the list
    void appendNode(Node *n) // Passing the address of the Node (for permanent change)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Append another Node with a different key value" << endl;
        }
        else
        {
            if (head == NULL) // if DLL is empty
            {
                head = n;
                cout << "Node appended as HEAD Node" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout << "Node Appended" << endl;
            }
        }
    }

    // 3. Prepend Node to the list
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Prepend another node with a different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node prepended as HEAD Node" << endl;
            }
            else
            {
                head->prev = n;
                n->next = head;

                head = n;
                cout << "Node Prepended" << endl;
            }
        }
    }

    // 4. Insert Node after a particular node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value: " << n->key << ". Append another node with a different key value" << endl;
            }
            else
            {
                cout << "Inserting..." << endl;

                Node *nextNode = ptr->next;

                // inserting at the end
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node Inserted at the END" << endl;
                }
                // inserting in between
                else
                {
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr->next = n;
                    cout << "Node Inserted in BETWEEN" << endl;
                }
            }
        }
    }

    // 5. Deleting a Node by unique key
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node UNLINKED with key value: " << k << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->prev;
                // Deleting at the end
                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "Node Deleted at the END" << endl;
                }
                // deleting in between
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout << "Node Deleted in BETWEEN" << endl;
                }
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
            cout << "No node exists with key value: " << k << endl;
        }
    }

    // 7. Printing the Doubly Linked List
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in the Doubly Linked List" << endl;
        }
        else
        {
            cout << endl
                 << "Doubly Linked List Values: ";
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    cout << "(" << temp->key << ", " << temp->data << ")";
                    break;
                }
                cout << "(" << temp->key << ", " << temp->data << ") <--> ";
                temp = temp->next;
            }
        }
    }
};

// main function
int main()
{
    cout << "-- Doubly Linked List --" << endl;

    DoublyLinkedList DLL;
    int menuOption, inputNewKey, inputExistingKey, inputNewData;

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

        cin >> menuOption;

        Node *n1 = new Node(); // Dynamic memory allocation (allocated on the heap)

        switch (menuOption)
        {
        case 0:
            cout << "Bye!" << endl;

            break;

        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> inputNewKey;
            cin >> inputNewData;
            n1->key = inputNewKey;
            n1->data = inputNewData;

            DLL.appendNode(n1);

            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> inputNewKey;
            cin >> inputNewData;
            n1->key = inputNewKey;
            n1->data = inputNewData;

            DLL.prependNode(n1);

            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this new Node" << endl;
            cin >> inputExistingKey;
            cout << "Enter key & data of the new Node first: " << endl;
            cin >> inputNewKey;
            cin >> inputNewData;
            n1->key = inputNewKey;
            n1->data = inputNewData;

            DLL.insertNodeAfter(inputExistingKey, n1);

            break;

        case 4:
            cout << "Delete Node by Key Operation \nEnter key of the Node to be Deleted: ";
            cin >> inputExistingKey;

            DLL.deleteNodeByKey(inputExistingKey);

            break;

        case 5:
            cout << "Update Node by Key Operation \nEnter key & NEW data to be updated" << endl;
            cin >> inputExistingKey;
            cin >> inputNewData;

            DLL.updateNodeByKey(inputExistingKey, inputNewData);

            break;

        case 6:
            DLL.printList();
            cout << endl;

            break;

        case 7:
            system("clear");

            break;

        default:
            cout << "Enter a Valid Option Number from 0 to 7!" << endl;

            break;
        }

    } while (menuOption != 0);
} // end of main