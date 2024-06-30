#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node *left, *right;
};
class BST{
    public:
    node *root;
    BST():root(NULL){}
    node *create(int value){
        node *newnode = new node;
        newnode->value = value;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    void BFS(){
        if(root == NULL)
            return;
        queue <node*> q;
        q.push(root);
        while(!q.empty()){
            node *a = q.front();
            q.pop();
            int l = -1, r = -1;
            if(a->left!=NULL){
                l = a->left->value;
                q.push(a->left);
            }
            if(a->right!=NULL){
                r = a->right->value;
                q.push(a->right);
            }
            cout << "Node: " << a->value;
            cout << " Left: " << l;
            cout << " Right: " << r << "\n";
        }
    }
    void Insert(int value){
        node *newnode = create(value);
        if(root == NULL){
            root = newnode;
            return;
        }
        node *cur = root;
        node *prv = NULL;
        while(cur!=NULL){
            if(newnode ->value > cur-> value){
                prv = cur;
                cur = cur->right;
            }
            else{
                prv = cur;
                cur = cur -> left;
            }
        }
        if(newnode ->value > prv->value)
            prv->right = newnode;
        else
            prv->left = newnode;
    }
    bool search(int value){
        node *cur = root;
        while(cur!=NULL){
            if(value > cur ->value)
                cur = cur->right;
            else if(value < cur ->value)
                cur = cur->left;
            else
                return true;
        }
        return false;
    }/*
    void Delete(int value){
        node *cur = root;
        node *prv = NULL;
        while(cur!=NULL){
            if(value > cur->value){
                prv = cur;
                cur = cur->right;
            }
            else if(value < cur->value){
                prv = cur;
                cur = cur->left;
            }
            else
                break;
        }
        if(cur == NULL){
            cout << "\nValue didn't found";
            return;
        }
        //If both child is NULL
        if(cur->left == NULL && cur->right == NULL){
            if(prv->left!=NULL && prv->left->value == cur->value)
                prv->left = NULL;
            else
                prv->right = NULL;
            delete cur;
            return;
        }
        //If there Has one child
        if(cur->left == NULL && cur->right!=NULL){
            if(prv->left!=NULL && prv->left->value == cur ->value)
                prv->left = cur->right;
            else
                prv->right = cur->right;
            delete cur;
            return;
        }
        if(cur->left!=NULL && cur->right ==NULL){
            if(prv ->left!=NULL && prv->left->value == cur->value)
                prv->left = cur->left;
            else
                prv->right = cur->left;
            delete cur;
            return;
        }
        //If there has two child
        node *tmp = cur->right;
        while(tmp->left!=NULL){
            tmp = tmp->left;
        }
        int save = tmp->value;
        Delete(save);
        cur->value = save;
    }*/
    void Delete(int value){
        root = deleteNode(root, value);
    }
    private:
    node* deleteNode(node* root, int key) {
        if (root == NULL) 
            return root;
        if (key < root->value)
            root->left = deleteNode(root->left, key);
        else if (key > root->value)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                node *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                node *temp = root->left;
                delete root;
                return temp;
            }
            node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
        return root;
    }
    node* minValueNode(node* n) {
        node* current = n;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
};
int main(){
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    bst.Delete(8);
    bst.BFS();
    bst.Delete(7);
    bst.BFS();

    bst.Delete(6);
    bst.BFS();
}
