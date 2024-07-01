#include<bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    Tree *left, *right;
};
//level-order (breadth-first) traversal, nodes are processed level by level,
//from left to right within each level. during level-order traversal, 
//node  (and its children) is processed before another node
bool IsPerfectTree(Tree *root){
    if(root == nullptr)
        return true;
    queue<Tree*>q;
    q.push(root);
    
    bool LeafEncounted = false;
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        level++;
        while(size--){
            Tree *node = q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
                if(LeafEncounted && (node->left || node->left->left || node->left->right))
                    return false;
            }
            if(node->right!=NULL){
                q.push(node->right);
                if(LeafEncounted &&(node ->left || node->right->left || node->right->right))
                    return false;
            }
            if(node->left == NULL && node->right == NULL){
                // it means this is the first leaf node encountered.
                if(!LeafEncounted)
                    LeafEncounted = true;
                    //If levelChecked is already true & the current level is not equal
                //to the level where the first leaf node was encountered,
                //it means the leaf nodes are not all at the same level.
                else if(level!= LeafEncounted)
                    return false;
            }
        }
    }
    return true;
}
bool IsCompleteTree(Tree *root){
    if(root == nullptr)
        return true;
    queue<Tree*>q;
    q.push(root);
    bool FullEncounted = false;
    while(!q.empty()){
        Tree *cur = q.front();
        q.pop();
        if(cur == nullptr)
            FullEncounted = true;
        else{
            if(FullEncounted)
                return false;
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return true;
}
int main(){
    //For objects, brace-initialization can be used to initialize members via initializer lists.
    //This is especially useful for aggregate types like structs and classes without user-defined constructors.
    Tree* root = new Tree{1};
    root->left = new Tree{2};
    root->right = new Tree{3};
    root->left->left = new Tree{4};
    root->left->right = new Tree{5};
    root->right->left = new Tree{6};
    root->right->right = new Tree{7};

    if (IsPerfectTree(root)) {
        cout << "The binary tree is perfect." << std::endl;
    } else {
        cout << "The binary tree is not perfect." << endl;
    }
    if (IsCompleteTree(root))
        cout << "It's a Complete Binary Tree." << endl;
    else
        cout << "It's not a Complete Binary Tree." << endl;
}
