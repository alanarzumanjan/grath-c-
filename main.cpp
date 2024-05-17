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

    Node* add(Node* node, int val) {
        if (node == nullptr){
            return new Node(val);
        }

        if (val < node->data){
            node->left = add(node->left, val);
        }
        else if (val > node->data){
            node->right = add(node->right, val);
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

    void in_order(Node* node) {
        if (node != nullptr)
        {
            in_order(node->left);
            cout << node->data << " ";
            in_order(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void add(int val)
    {
        root = add(root, val);
    }

    bool search(int val)
    {
        return search(root, val);
    }

    void in_order() {
        in_order(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree Tree;

    for(int i = 0; i < 20; i++){
        int random = rand() % 48;
        Tree.add(random);
    }

    cout << "in_order: ";
    Tree.in_order();

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
