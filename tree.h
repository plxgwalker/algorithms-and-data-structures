#pragma once
#include <iostream>

using namespace std;
typedef int datatype;

struct Node {
    datatype key;
    Node* left;
    Node* right;
    Node* parent;
};

void createTree(Node*& pNode, int n);
void showTree(Node*& pNode, int l);

void prefixOrder(Node* pNode);
void postfixOrder(Node* pNode);
void infixOrder(Node* pNode);

Node* searchNodeBST(Node* pNode, int key);
Node* createRootBST(Node*& pNode);
int insertNodeBST(Node*& pNode, int key);
Node* minimumNodeBST(Node*& pNode);
Node* maximumNodeBST(Node*& pNode);
Node* successorNodeBST(Node*& pNode);
Node* predcessorNodeBST(Node*& pNode);
void deleteNodeBST(Node*& delNode, int value);