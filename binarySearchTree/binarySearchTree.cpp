#include "binarySearchTree.hpp"

void BinarySearchTree::addNode(int key) {
    rootNode = addNode(key, rootNode);
}

Node* BinarySearchTree::addNode(int key, Node*& root) {
    if (nullptr == root)
        return new Node(key);
    
    if (key <= root->key)
        root->left = addNode(key, root->left);
    else
        root->right = addNode(key, root->right);

    return root;
}

void BinarySearchTree::preorderTraversal() {
    preorderTraversal(rootNode);
    cout << "\n";
}

void BinarySearchTree::preorderTraversal(Node*& root) {
    if (nullptr == root) return;

    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void BinarySearchTree::postorderTraversal() {
    postorderTraversal(rootNode);
    cout << "\n";
}

void BinarySearchTree::postorderTraversal(Node*& root) {
    if (nullptr == root) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << " ";
}

void BinarySearchTree::inorderTraversal() {
    inorderTraversal(rootNode);
    cout << "\n";
}

void BinarySearchTree::inorderTraversal(Node*& root) {
    if (nullptr == root) return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

bool BinarySearchTree::compare(Node*& other) {
    return compare(rootNode, other);
}

bool BinarySearchTree::compare(Node*&root, Node*& other) {
    if (nullptr == root && nullptr == other) return true;
    if (nullptr == root || nullptr == other) return false;
    
    if (root->key != other->key) return false;

    bool leftResult = compare(root->left, other->left);
    bool rightResult = compare(root->right, other->right);

    return leftResult && rightResult;
}

int BinarySearchTree::getHeight() {
    return getHeight(rootNode);
}

int BinarySearchTree::getHeight(Node*& rootNode) {
    if (nullptr == rootNode) return 0;

    int leftHeight = getHeight(rootNode->left);
    int rightHeight = getHeight(rootNode->right);

    return max(leftHeight, rightHeight) + 1;
}

void BinarySearchTree::levelOrderTraversal() {
    int height = getHeight(rootNode);
    for (int i = 1; i <= height; ++i) levelOrderTraversal(rootNode, i);
    cout << "\n";
}

void BinarySearchTree::levelOrderTraversal(Node*& root, int currHeight) {
    if (nullptr == root) return;
    
    if (1 == currHeight) {
        cout << root->key << " ";
    } else {
        levelOrderTraversal(root->left, currHeight - 1);
        levelOrderTraversal(root->right, currHeight - 1);
    }
}
