#include <iostream>
using namespace std;
struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree(int x) : val(x), left(NULL), right(NULL) {}
};
int findHeight(Tree* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}
int findMin(Tree* root) {
    if (root == nullptr) {
        return -1;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->val;
}
int main() {
    Tree* root = new Tree(5);
    root->left = new Tree(3);
    root->right = new Tree(8);
    root->left->left = new Tree(2);
    root->left->right = new Tree(4);
    int minVal = findMin(root);
    cout << "The minimum value in the BST is: " << minVal << "\n";

    int height = findHeight(root);
    cout << "Height of the binary tree is: " << height ;
    return 0;
}
