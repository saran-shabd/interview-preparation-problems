#ifndef binarySearchTree
#define binarySearchTree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;

    explicit Node(int& key): key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* rootNode;
    
    BinarySearchTree(): rootNode(nullptr) {}

    void addNode(int key);
    void preorderTraversal();
    void postorderTraversal();
    void inorderTraversal();
    void levelOrderTraversal();
    int getHeight();
    bool compare(Node*& other);
    int size();

private:

    Node *addNode(int key, Node*& root);
    void preorderTraversal(Node*& root);
    void postorderTraversal(Node*& root);
    void inorderTraversal(Node*& root);
    void levelOrderTraversal(Node*& root, int currHeight);
    bool compare(Node*&root, Node*& other);
    int getHeight(Node*& root);
};

#endif
