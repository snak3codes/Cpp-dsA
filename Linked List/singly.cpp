#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next; // Pointer to another Node.
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
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    { // pass by address = *n
        head = n;
    }

    // Methods
    // 1. Check if node exists in the Linked List using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }
        return temp;
    }

    // 2. Append a node to the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL) // Accessing pointer data members using ->
        {
            cout << "Node already exists with key value: " << n->key << ". Append another node with a different key value" << endl;
        }
        else
        {
            // No node initially in the Linked List
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }
            else
            {
                // Linked List not empty
                Node *ptr = head;
                while (ptr->next != NULL) // Traverse to the last node
                {
                    ptr = ptr->next;
                }
                ptr->next = n; // Append node after last node
                cout << "Node Appended" << endl;
            }
        }
    }

    // 3. Prepend a node to the list
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL) // Accessing pointer data members using ->
        {
            cout << "Node already exists with key value: " << n->key << ". Prepend another node with a different key value" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }

    // 4. Insert a Node after a particular Node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k); // ptr will point to node with key "k"
        if (ptr == NULL)
        { // No node exists with key "k" in the list
            cout << "Node with key value: " << k << " does not exist" << endl;
        }
        else // Node exists with key "k" in the list
        {
            if (nodeExists(n->key) != NULL) // New has duplicate key in the list
            {
                cout << "Node already exists with key value: " << n->key << ". Append another node with a different key value" << endl;
            }
            else // new has unique key in the list
            {
                n->next = ptr->next; // Make new's next, point to the next of its previous
                ptr->next = n;
                cout << "Node Inserted" << endl;
            }
        }
    }

    // 5. Delete Node by unique key
    void deleteNodeByKey(int k)
    {
        if (head == NULL) // Empty SLL
        {
            cout << "Singly Linked List already Empty. Can't delete" << endl;
        }
        else if (head != NULL) // Head exists
        {
            if (head->key == k) // key passed matches head
            {
                head = head->next;
                cout << "Node UNLIKED with key value: " << k << endl;
            }
            else // delete a node in the SLL which is not the head
            {
                Node *temp = NULL;
                Node *prevPtr = head;
                Node *currPtr = head->next;
                while (currPtr != NULL) // Traversing the list
                {
                    if (currPtr->key == k)
                    {
                        temp = currPtr;
                        currPtr = NULL; // toggling flag to false (avoid unnecessary traversing to the end)
                    }
                    else
                    {
                        prevPtr = prevPtr->next;
                        currPtr = currPtr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevPtr->next = temp->next; // Unlinking temp (Node to be deleted)
                    cout << "Node UNLIKED with keys value: " << k << endl;
                }
                else
                {
                    cout << "Node with key value: " << k << " does not exist" << endl;
                }
            }
        }
    }

    // 6. Update Node by Key with new Data
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k); // Returns a pointer to a particular node that matches the key "k" if it exists in the Linked List
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data updated successfully" << endl;
        }
        else
        {
            cout << "Node with key value: " << k << " does not exist" << endl;
        }
    }

    // 7. Printing the Linked List
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in the Singly Linked List" << endl;
        }
        else
        {
            cout << endl
                 << "Singly Linked List Values: ";
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    cout << "(" << temp->key << ", " << temp->data << ")";
                    break;
                }
                cout << "(" << temp->key << ", " << temp->data << ") --> ";
                temp = temp->next;
            }
        }
    }
};

// main function
int main()
{
    cout << "-- Singly Linked List --" << endl;

    SinglyLinkedList SLL;
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

            SLL.appendNode(n1);

            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> inputNewKey;
            cin >> inputNewData;
            n1->key = inputNewKey;
            n1->data = inputNewData;

            SLL.prependNode(n1);

            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this new Node" << endl;
            cin >> inputExistingKey;
            cout << "Enter key & data of the new Node first: " << endl;
            cin >> inputNewKey;
            cin >> inputNewData;
            n1->key = inputNewKey;
            n1->data = inputNewData;

            SLL.insertNodeAfter(inputExistingKey, n1);

            break;

        case 4:
            cout << "Delete Node by Key Operation \nEnter key of the Node to be Deleted: ";
            cin >> inputExistingKey;

            SLL.deleteNodeByKey(inputExistingKey);

            break;

        case 5:
            cout << "Update Node by Key Operation \nEnter key & NEW data to be updated" << endl;
            cin >> inputNewKey;
            cin >> inputNewData;

            SLL.updateNodeByKey(inputNewKey, inputNewData);

            break;

        case 6:
            SLL.printList();
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

    return 0;
} // end of main