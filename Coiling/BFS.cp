#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int id;
    node *left, *right, *parent;
    node(int id) : id(id), left(NULL), right(NULL), parent(NULL) {}
};
class BinaryTree {
public:
    node *root;
    node *allnode[6];
    BinaryTree() {
        root = NULL;
        for(int i = 0; i < 6; i++)
            allnode[i] = NULL;
    }
    node* create(int id){
        return new node(id);
        /*
        node *newnode = new node;
        newnode->id = id;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        return newnode; */
    }
    void build() {
        for(int i = 0; i < 6; i++)
            allnode[i] = create(i);
        
        allnode[0]->left = allnode[1];
        allnode[0]->right = allnode[2];
        allnode[1]->left = allnode[5];
        allnode[1]->parent = allnode[0];
        allnode[2]->left = allnode[3];
        allnode[2]->right = allnode[4];
        allnode[2]->parent = allnode[0];
        allnode[5]->parent = allnode[1];
        allnode[3]->parent = allnode[2];
        allnode[4]->parent = allnode[2];
        root = allnode[0];
    }
    void Insert(int id){
        node *newnode = create(id);
        if(root == NULL){
            root = newnode;
            return;
        }
        queue <node*> q;
        q.push(root);
        while(!q.empty()){
            node *a = q.front();
            q.pop();
            if(a->left!=NULL)
                 q.push(a->left);
            else{
                a->left = newnode;
                newnode->parent = a;
            }
            if(a->right!=NULL)
                q.push(a->right);
            else{
                a->right = newnode;
                newnode->parent = a;
            }
        }
    }
    void BFS(){
        if(root == NULL)
            return;
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node *a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->left!=NULL){
                l = a->left->id;
                q.push(a->left);
            }
            if(a->right!=NULL){
                r = a->right->id;
                q.push(a->right);
            }
            if(a->parent!=NULL)
                p = a->parent->id;
            cout << "Node: " << a->id;
            cout << " parent: " << p;
            cout << " Left: " << l;
            cout << " Right: " << r << "\n";
        }
    }
    void print() {
        for(int i = 0; i < 6; i++) {
            int p = -1, l = -1, r = -1;
            if(allnode[i]->parent != NULL)
                p = allnode[i]->parent->id;
            if(allnode[i]->left != NULL)
                l = allnode[i]->left->id;
            if(allnode[i]->right != NULL)
                r = allnode[i]->right->id;
            cout << "Node: " << allnode[i]->id;
            cout << " parent: " << p;
            cout << " Left: " << l;
            cout << " Right: " << r << "\n";
        }
    }
};
int main() {
    BinaryTree bt;
    bt.build();
    //bt.print();
    bt.Insert(4);
    bt.BFS();
    return 0;
}
