#include<bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    Tree *left, *right;
};
int Findmax(Tree *root){
    if(root == nullptr)
        return INT_MIN;
    if(root->right == nullptr)
        return root->data;
    return Findmax(root->right);
}
int main(){
    Tree* root = new Tree{10, nullptr, nullptr};
    root->left = new Tree{5, nullptr, nullptr};
    root->right = new Tree{15, nullptr, nullptr};
    root->left->left = new Tree{3, nullptr, nullptr};
    root->left->right = new Tree{8, nullptr, nullptr};

    int maxValue = Findmax(root);
    cout << "Maximum value in the BST: " << maxValue ;
}
