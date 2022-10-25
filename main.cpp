#include "tree.h"

int main() {
    Node* root = 0;
    Node* root1 = 0;
    int value = 0;
    int nodes = 0;
    int choice = 1;

    while (choice != 0)
    {
        cout << "1 - Create binary tree" << endl;
        cout << "2 - Show binary tree" << endl;
        cout << "3 - Show in prefix order binary tree" << endl;
        cout << "4 - Show in postfix order binary tree" << endl;
        cout << "5 - Show in infix order binary tree" << endl;
        cout << "6 - Create root for BST" << endl;
        cout << "7 - Insert new node for BST" << endl;
        cout << "9 - Delete node" << endl;
        

        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Please enter the quantity of nodes: ";
            cin >> nodes;
            createTree(root, nodes);
            cout << endl;
            break;
        case 2:
            cout <<"Binary tree: " << endl << endl;
            showTree(root, 0);
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Prefix order: " << endl;
            prefixOrder(root);
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "Postfix order: " << endl;
            postfixOrder(root);
            cout << endl;
            break;
        case 5:
            cout << endl;
            cout << "Infix order: " << endl;
            infixOrder(root);
            cout << endl;
            break;
        case 6:
            cout << endl;
            createRootBST(root1);
            cout << "Root for BST has been created" << endl;
            break;
        case 7:
            cout << endl;
            cout << "Please enter value for new node: ";
            cin >> value;
            insertNodeBST(root1, value);
            break;
        case 8:
            cout << endl;
            cout << "Binary Search tree: " << endl << endl;
            showTree(root1, 0);
            cout << endl;
            break;
        case 9:
            cout << endl;
            cout << "Please enter value for node: ";
            cin >> value;
            deleteNodeBST(root1, value);
            break;
        default:
            break;
        }
    }



    

}