#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int id, value;
    node *left, *right, *parent;
};
class BinaryTree{
    public: node *root;
    BinaryTree(){
        root = NULL;
    }
    node *create(int id, int value){
        node *newnode = new node;
        newnode ->id = id;
        newnode ->value = value;
        newnode ->left = NULL;
        newnode ->right = NULL;
        newnode ->parent = NULL;
        return newnode;
    }
    void InsertNode(int id, int value){
        node *newnode = create(id, value);
        if(root == NULL){
            root = newnode;
            return;
        }
        queue <node*> q;
        q.push(root);
        while(!q.empty()){
            node *a = q.front();
            q.pop();
            
            if(a->left!=NULL){
                q.push(a->left);
            }
            else{
                newnode->parent = a;
                a->left = newnode;
                return ;
            }
            if(a->right!=NULL)
                q.push(a->right);
            else{
                newnode->parent = a;
                a->right = newnode;
                return;
            }
        }
    }
    void BFS(){
        if(root == NULL)
            return;
        queue <node*> q;
        q.push(root);
        while(!q.empty()){
            node *a = q.front();
            q.pop();
            int l = -1, r = -1, p = -1;
            if(a->left!=NULL){
                q.push(a->left);
                l = a->left->id;
            }
            if(a->right!=NULL){
                q.push(a->right);
                r = a->right->id;
            }
            if(a->parent!=NULL)
                p = a->parent->id;
            cout << "Node: " << a->id ;
            cout << " Left child: " << l ;
            cout<< " right child: " << r ;
            cout << " parent: " << p << "\n";
        }
    }
    void DFS(node *a){
        if(a == NULL)
            return;
        cout << a->id << " ";
        DFS(a->left);
        DFS(a->right);
    }
    void InOrder(node *a){
        if(a == NULL)
            return;
        InOrder(a->left);
        cout << a->id << " ";
        InOrder(a->right);
    }
    void PreOrder(node *a){
        if(a == NULL)
            return;
        cout << a->id << " ";
        PreOrder(a->left);
        PreOrder(a->right);
    }
    void PostOrder(node *a){
        if(a == NULL)
            return;
        PostOrder(a->left);
        PostOrder(a->right);
        cout << a->id << " ";
    }
    void search(node *a, int value){
        if(a == NULL)
            return;
        if(a->value == value)
            cout << a->id ;
        search(a->left, value);
        search(a->right, value);
    }
};
int main(){
    BinaryTree bt;
    bt.InsertNode(0, 2);
    bt.InsertNode(1, 5);
    bt.InsertNode(2, 3);
    bt.InsertNode(3, 9);
    bt.InsertNode(4, 1);
    bt.BFS();
    cout << "\nAfter DFS: ";
    bt.DFS(bt.root);
    cout << "\nElements found at idx: ";
    bt.search(bt.root, 5);
    cout << "\nElements found at idx: ";
    bt.search(bt.root, 1);
}
