#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
    }
};

class BinarySearchTree {

private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr){
            return new Node(val);
        }

        if (val < node->data){
            node->left = insert(node->left, val);
        }
        else if (val > node->data){
            node->right = insert(node->right, val);
        }

        return node;
    }

    bool search(Node* node, int val) {
        if (node == nullptr){
            return false;
        }

        if (val == node->data){
            return true;
        } 
        else if (val < node->data){
            return search(node->left, val);
        } 
        else{
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

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree Tree;

    for(int i = 0; i < 20; i++){
        int random = rand() % 48;
        Tree.insert(random);
    }

    cout << "Inorder: ";
    Tree.inorder();

    int key;
    cout << "Enter search number: ";
    cin >> key;

    if (Tree.search(key)){
        cout << key << " found" << endl;
    } else{
        cout << key << " not found" << endl;
    }

    return 0;
}
