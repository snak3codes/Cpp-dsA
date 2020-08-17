/* Binary SEARCH Tree as dynamic nodes in memory
Node(* left, data, *right)
*/

#include <iostream>
#define SPACE 10

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;

    BST()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value Inserted as root node" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value already exists,"
                         << "Insert another value" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value Inserted to the left" << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the right" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // base case
            return;
        space += SPACE;           // Increase distance between levels
        print2D(r->right, space); // Process right child first
        cout << endl;
        for (int i = SPACE; i < space; i++) // Print current node after space count
            cout << " ";
        cout << r->value << "\n";
        print2D(r->left, space); // Process left child
    }
};

int main()
{
    int option, val;
    BST bstObj;

    do
    {
        cout << "What operation do you want to perform?"
             << " Select Option Number. Enter 0 to Exit." << endl;

        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST Values" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Insert" << endl;
            cout << "Enter Value of Tree Node to Insert in BST: ";
            cin >> val;
            new_node->value = val;
            bstObj.insertNode(new_node);
            cout << endl;
            break;
        case 2:
            cout << "Search" << endl;
            break;

        case 3:
            cout << "Delete" << endl;
            break;

        case 4:
            cout << "Print" << endl;
            bstObj.print2D(bstObj.root, 5);
            break;

        case 5:
            system("clear");
            break;

        default:
            break;
        }

    } while (option != 0);

    return 0;
}
