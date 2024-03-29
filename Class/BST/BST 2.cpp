#include <iostream>
using namespace std;
class Tree {
public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree {
private:
    Tree* root;
    Tree* insert(Tree* root, int value) {
        if (root == nullptr) {
            return new Tree(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }
    bool search(Tree* root, int value) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == value) {
            return true;
        } else if (value < root->data) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }
    public:
    BinaryTree() {
        root = nullptr;
    }
    void insert(int value) {
        root = insert(root, value);
    }
    bool search(int value) {
        return search(root, value);
    }
};
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    if (tree.search(4))
        cout << "Value 4 found in the tree." ;
    else
        cout << "Value 4 not found in the tree.";
    return 0;
}
