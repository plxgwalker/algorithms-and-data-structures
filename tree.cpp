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
    if (pNode != NULL)
    {
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
    while(pNode != NULL) {
        if (pNode->key == key) return pNode;
        else if (pNode->key > key) pNode = pNode->left;
        else if (pNode->key < key) pNode = pNode->right;
    }
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
    while (pNode->left != NULL) pNode = pNode->left;
    return pNode;
}

Node* maximumNodeBST(Node*& pNode) {
    while (pNode->right != NULL) pNode = pNode->right;
    return pNode;
}

Node* successorNodeBST(Node*& pNode) {
    if (pNode->right != NULL) {
        return minimumNodeBST(pNode->right);
    }
    Node* y = pNode->parent;
    while (y != NULL && pNode == y->right) {
        pNode = y;
        y = y->parent;
    }
    return y;
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

Node* DelNodeBST(Node*& delNode, datatype value) {
    if (searchNodeBST(delNode, value) == NULL) cout << "No value" << endl;

    else if (delNode == NULL) return delNode;
    else if (delNode->key > value) DelNodeBST(delNode->left, value);
    else if (delNode->key < value) DelNodeBST(delNode->right, value);

    else if (delNode->left == NULL && delNode->right == NULL) 
    {
        delete delNode;
        delNode = NULL;
    }
    else if (delNode->left == NULL) 
    {
        Node* temp = delNode;
        delNode = delNode->right;
        delete temp;
    }
    else if (delNode->right == NULL) {
        Node* temp = delNode;
        delNode = delNode->left;
        delete temp;
    }
    else {
        Node* temp = delNode->left;

        while (temp->right != NULL) temp = temp->right;

        delNode->key = temp->key;
        delNode->left = DelNodeBST(delNode->left, temp->key);
    }

    return delNode;
}
