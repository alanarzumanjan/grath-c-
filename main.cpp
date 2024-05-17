#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* insert(Node* node, int val) {

        if (val < node->data) 
        {
            node->left = insert(node->left, val);
        } 
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    bool search(Node* node, int val) {

        if (val == node->data)
        {
            return true;
        } 
        else if (val < node->data)
        {
            return search(node->left, val);
        } 
        else
        {
            return search(node->right, val);
        }
    }

    void inorder(Node* node) {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val)
    {
        root = insert(root, val);
    }

    bool search(int val)
    {
        return search(root, val);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(9);
    tree.insert(11);
    tree.insert(16);
    tree.insert(22);
    

    cout << "Inorder: ";
    tree.inorder();

    int key;
    cout << "Enter seach number: ";
    cin >> key;
    if (tree.search(key))
    {
        cout << key << " found" << endl;
    } 
    else
    {
        cout << key << " not found" << endl;
    }

    return 0;
}
