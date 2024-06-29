#include <iostream>
#include <queue>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {}
};
void bfs(Tree* root) {
    if (root == nullptr) return;

    queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        Tree* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

void inOrder(Tree* root) {
    if (root == nullptr) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Tree* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Tree* root) {
    if (root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    cout << "BFS Traversal: ";
    bfs(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;
    return 0;
}
