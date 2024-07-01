#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
    int data;
    Tree *left, *right;
    Tree(int val):data(val), left(nullptr), right(nullptr){}
};
class BT{
    private:
    Tree *root;
    Tree *Insert(Tree *root, int val){
        if(root == nullptr)
            return new Tree(val);
        //If the value is less, the function recursively calls insert on the left subtree
        //result of this recursive call (which could be a new or
        //existing left child) is assigned back to root->left.
        if(val < root->data)
            root->left = Insert(root->left, val);
        else if(val > root->data)
            root->right = Insert(root->right, val);
        else
        //After handling both conditions,function returns the root node.
        //This ensures that as the recursion unwinds, the original root node 
        //(or its updated structure) is propagated back up the call stack.
            return root;
    }
    bool search(Tree *root, int val){
        if(root == nullptr)
            return false;
        if(root->data == val)
            return true;
        else if(val > root->data)
            return search(root->right, val);
        else
            return search(root->left, val);
    }
    public:
    BT(){
        root = nullptr;
    }
    void Insert(int val){
        root = Insert(root, val);
    }
    bool search(int val){
        return search(root, val);
    }
};
int findHeight(Tree *root){
    if(root == nullptr)
        return 0;
    else{
        int LHeight = findHeight(root->left);
        int RHeight = findHeight(root->right);
    return 1 + max(LHeight, RHeight);
    }
}
int findMin(Tree *root){
    if(root == nullptr)
        return -1;
    while(root->left!=nullptr){
        root = root->left;
    }
    return root->data;
}
int main(){
    BT tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    if (tree.search(4))
        cout << "Value 4 found in the tree." ;
    else
        cout << "Value 4 not found in the tree.";
    //
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
