#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};
//level-order (breadth-first) traversal, nodes are processed level by level, from left to right within each level.
bool isPerfectBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    bool levelChecked = false;
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();
        level++;
        
        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                q.push(node->left);
                
                if (levelChecked && (node->right || node->left->left || node->left->right)) {
                    return false;
                }
            }
            
            if (node->right) {
                q.push(node->right);
                
                if (levelChecked && (node->left || node->right->left || node->right->right)) {
                    return false;
                }
            }
            
            if (!node->left && !node->right) {
                if (!levelChecked) {
                    // if (!levelChecked): If levelChecked is false, it means this is the first leaf node encountered.
                    levelChecked = true;
                } else if (level != levelChecked) {
                    return false;
                }
            }
        }
    }
    return true;
}
bool isCompleteBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root);
    bool nonFullNodeEncountered = false;

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current == nullptr) {
            nonFullNodeEncountered = true;
        } else {
            if (nonFullNodeEncountered)
                return false;

            q.push(current->left);
            q.push(current->right);
        }
    }
    return true;
}
int main() {
    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->left->left = new TreeNode{4};
    root->left->right = new TreeNode{5};
    root->right->left = new TreeNode{6};
    root->right->right = new TreeNode{7};

    if (isPerfectBinaryTree(root)) {
        cout << "The binary tree is perfect." << std::endl;
    } else {
        cout << "The binary tree is not perfect." << endl;
    }
    if (isCompleteBinaryTree(root))
        cout << "It's a Complete Binary Tree." << endl;
    else
        cout << "It's not a Complete Binary Tree." << endl;
    return 0;
}
