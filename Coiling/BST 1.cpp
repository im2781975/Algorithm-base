#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int value;
    node* left, * right;
    node(int value) {
        this->value = value;
        left = NULL; right = NULL;
    }
};
class BST {
    public:
    node* root;
    BST():root(NULL){}
    void insert(int value) {
        node* newnode = new node(value);
        if (root == NULL) {
            root = newnode;
            return;
        }
        node* cur = root;
        node* prv = NULL;
        while (cur != NULL) {
            prv = cur;
            if (value > cur->value)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (value > prv->value)
            prv->right = newnode;
         else
            prv->left = newnode;
    }
    void display() {
        if (root == NULL) {
            cout << "nothing" << "\n";
            return;
        }
        node* tmp = root;
        queue<node*> q;
        q.push(root);
        while (q.empty() == false) {
            node* a = q.front();
            cout << a->value;

            if (a->left != NULL)
                q.push(a->left);
            if (a->right != NULL)
                q.push(a->right);
            q.pop();
        }
    }
    bool find(int value) {
        if (root == NULL)
            return false;

        node* tmp = root;
        while (tmp != NULL) {
            if (value > tmp->value) {
                tmp = tmp->right;
            } else if (value < tmp->value)
                tmp = tmp->left;
             else
                return true;
        }
        return false;
    }
    void delete_node(int value) {
        if (find(value) == true) {
            node* cur = root;
            node* prv = NULL;
            while (cur != NULL) {
                if (value > cur->value) {
                    prv = cur;
                    cur = cur->right;
                } else if (value < cur->value) {
                    prv = cur;
                    cur = cur->left;
                } else {
                    break;
                }
            }
            if (cur->left == NULL && cur->right == NULL) {
                node* delnode = cur;
                if (prv->right != NULL && value > prv->right->value) {
                    prv->right = NULL;
                } else {
                    prv->left = NULL;
                }
                delete delnode;
                return;
            }
            // node exit one child.
            if (cur->left != NULL && cur->right == NULL) {
                node* delnode = cur->left;
                cur->value = cur->left->value;
                cur->left = NULL;
                delete delnode;
                return;
            }
            if (cur->right != NULL && cur->left == NULL) {
                node* delnode = cur->left;
                cur->value = cur->right->value;
                cur->right = NULL;
                delete delnode;
                return;
            }
            if (cur->right != NULL && cur->left != NULL) {
                node* delnode = cur->right;
                cur->value = cur->left->value;
                cur->left = NULL;
                delete delnode;
                return;
            }
        }
        cout << "Not found";
    }
};
int main() {
    BST t;
    t.insert(10);
    t.insert(9);
    t.insert(8);
    t.display();
    if (t.find(8) == true)
        cout << "Exit";
    else
        cout << "not found";
    return 0;
}
