#include "tree.h"

void createTree(Node*& pNode, int n) {
    if (n == 0) {
        Node* pNode = NULL;
    }
    else if (n > 0) {
        datatype data;

        cout << "Please enter value for key: ";
        cin >> data;

        pNode = new Node;
        pNode->key = data;
        pNode->left = pNode->right = NULL;

        int n_left = 0;
        n_left = n / 2;

        createTree(pNode->left, n_left);

        int n_right = 0;
        n_right = n - n_left - 1;

        createTree(pNode->right, n_right);
    }
}

void showTree(Node*& pNode, int l){
    if (pNode != NULL) {
        showTree(pNode->right, l + 1);
        for (int i = 0; i < l; i++) cout << "\t";
        cout << pNode->key << endl;
        showTree(pNode->left, l + 1);
    }
}

void prefixOrder(Node* pNode) {
    if (pNode != NULL) {
        cout << pNode->key << " ";
        prefixOrder(pNode->left);
        prefixOrder(pNode->right);
    }
}

void postfixOrder(Node* pNode) {
    if (pNode != NULL) {
        postfixOrder(pNode->left);
        postfixOrder(pNode->right);
        cout << pNode->key << " ";
    }
}

void infixOrder(Node* pNode) {
    if (pNode != NULL) {
        infixOrder(pNode->left);
        cout << pNode->key << " ";
        infixOrder(pNode->right);
    }
}

// Binary Search Tree

Node* searchNodeBST(Node* pNode, int key) { // Пошук даних за ключем у бінарному дереві пошуку
    while(pNode) {
        if (pNode->key == key) return pNode;
        else if (pNode->key > key) pNode = pNode->left;
        else if (pNode->key < key) pNode = pNode->right;
    }
    return pNode;
}

Node* createRootBST(Node*& pNode) { // Створення бінарного дерева пошуку
    datatype data = 0;

    cout << "Please enter value for root: ";
    cin >> data;

    pNode = new Node;
    pNode->key = data;
    pNode->left = NULL;
    pNode->right = NULL;
    pNode->parent = NULL;

    return pNode;
}

int insertNodeBST(Node*& pNode, int key) {

    /* Перевірка чи існує вузол з ключем 'key' */
    if (searchNodeBST(pNode, key) != NULL) {
        cout << "Key already exists." << endl;
        return NULL;
    }

    /* Створення вузла 'z' */
    Node* z = new Node;
    z->key = key;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    Node* y = NULL;  // батьківський вузол
    Node* x = pNode; // поточний вузол

    /* Пошук в дереві */
    while (x != NULL)
    {
        y = x;

        if (z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;

    /* Створення кореня */
    if (y == NULL) pNode = z;

    /* Вставка вузла 'z' */
    else {
        if (z->key < y->key) y->left = z;
        else y->right = z;
    }
}

Node* minimumNodeBST(Node*& pNode) {
    Node* previous = pNode;
    while (previous->left != NULL) previous = previous->left;
    return previous;
}

Node* maximumNodeBST(Node*& pNode) {
    Node* previous = pNode;
    while (previous->right != NULL) previous = previous->right;
    return previous;
}

Node* successorNodeBST(Node*& pNode) {
    if (pNode->right != NULL) {
        return minimumNodeBST(pNode->right);
    }
    else {
        if (pNode->right == NULL) {
            Node* previous = pNode->parent;
            while (previous != NULL && pNode == previous->right)
            {
                pNode = previous;
                previous = previous->parent;
            }
            return previous;
        }
    }
}

Node* predcessorNodeBST(Node*& pNode) {
    if (pNode->right != NULL) {
        return maximumNodeBST(pNode->left);
    }
    else {
        if (pNode->right == NULL) {
            Node* previous = pNode->parent;
            while (previous != NULL && pNode == previous->left)
            {
                pNode = previous;
                previous = previous->parent;
            }
            return previous;
        }
    }
}

void deleteNodeBST(Node*& root, int key) {
    Node* delNode = searchNodeBST(root, key);
    if (delNode == NULL) {
        cout << "Key does not exists." << endl;
        return;
    }
    else {
        if (delNode->left == NULL && delNode->right == NULL) {
            if (delNode == root) {
                delete root;
            }
            else if (delNode == delNode->parent->left) {
                delNode->parent->left = NULL;
            }
            else if (delNode == delNode->parent->right) {
                delNode->parent->right = NULL;
            }
            delete delNode;
            showTree(root, 0);
        }

        else if (delNode->left != NULL || delNode->right != NULL) {
            Node* next = new Node;

            if (delNode->left != NULL) {
                next = delNode->left;
            }
            else {
                next = delNode->right;
            }

            if (delNode->parent != NULL) {
                if (delNode->parent->left->key == delNode->key) {
                    delNode->parent->left = next;
                }
                else {
                    delNode->parent->right = next;
                }

                next->parent = delNode->parent;
                delete delNode;
                showTree(root, 0);
            }

            else {
                root = next;
                delete delNode;
                showTree(root, 0);
            }
        }

        else if (delNode->left != NULL && delNode->right != NULL) {
            Node* term = successorNodeBST(delNode);
            int temp = delNode->key;
            delNode->key = term->key;
            term->key = temp;
            deleteNodeBST(term, key);
        }
    }
}