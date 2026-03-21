#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* CreateBinaryTree(Node* root) {
    cout << "Enter the data (-1 for NULL): " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the data to insert left of " << data << endl;
    root->left = CreateBinaryTree(root->left);

    cout << "Enter the data to insert right of " << data << endl;
    root->right = CreateBinaryTree(root->right);

    return root; 
}

int main() {
    Node* root = NULL;
    root = CreateBinaryTree(root); 
    return 0;
}