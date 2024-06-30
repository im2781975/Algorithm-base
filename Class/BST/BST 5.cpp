#include <bits/stdc++.h>
using namespace std;
struct tree {
    int data;
    tree *left, *right;
    tree(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST {
private:
    tree *root;
    tree *Insert(tree *root, int val) {
        if (root == nullptr)
            return new tree(val);
        if (val < root->data)
            root->left = Insert(root->left, val);
        else if (val > root->data)
            root->right = Insert(root->right, val);
        return root;
    }
    tree *Findmin(tree *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    tree *Delete(tree *root, int val) {
        if (root == nullptr)
            return root;
        if (val < root->data)
            root->left = Delete(root->left, val);
        else if (val > root->data)
            root->right = Delete(root->right, val);
        else {
            if (root->left == nullptr) {
                tree *tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == nullptr) {
                tree *tmp = root->left;
                delete root;
                return tmp;
            }
            tree *tmp = Findmin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
        return root;
    }
    bool Search(tree *root, int val) {
        if (root == nullptr)
            return false;
        if (root->data == val)
            return true;
        if (val > root->data)
            return Search(root->right, val);
        else
            return Search(root->left, val);
    }
    public:
    BST() : root(nullptr) {}
    void InsertVal(int val) {
        root = Insert(root, val);
    }
    void DeleteVal(int val) {
        root = Delete(root, val);
    }
    bool SearchVal(int val) {
        return Search(root, val);
    }
};
int main() {
    BST bst;
    bst.InsertVal(50);
    bst.InsertVal(30);
    bst.InsertVal(70);
    bst.InsertVal(20);
    bst.InsertVal(40);
    bst.InsertVal(60);
    bst.InsertVal(80);
    cout << "\nSearch for 40: " << (bst.SearchVal(40) ? "Found" : "Not found");
    cout << "\nSearch for 90: " << (bst.SearchVal(90) ? "Found" : "Not found");

    bst.DeleteVal(30);
    cout << "\nSearch for 30 after deletion: " << (bst.SearchVal(30) ? "Found" : "Not found");
    return 0;
}
