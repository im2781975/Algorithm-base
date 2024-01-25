#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    Tree* left;
    Tree* right;
};
int findMax(Tree* root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    if (root->right == nullptr)
        return root->data;

    return findMax(root->right);
}
int main() {
    Tree* root = new Tree{10, nullptr, nullptr};
    root->left = new Tree{5, nullptr, nullptr};
    root->right = new Tree{15, nullptr, nullptr};
    root->left->left = new Tree{3, nullptr, nullptr};
    root->left->right = new Tree{8, nullptr, nullptr};

    int maxValue = findMax(root);
    cout << "Maximum value in the BST: " << maxValue ;
    return 0;
}

