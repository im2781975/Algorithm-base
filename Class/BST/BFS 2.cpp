#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int id;
    node *left, *right, *parent;
};
class BinaryTree{
    public:
    node *root, *allnode[6];
    BinaryTree(){
        root =NULL;
    }
    node *create(int id){
        node *newnode = new node;
        newnode-> id =id;
        
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        return newnode;
    }
    void build(){
        for(int i = 0; i < 6; i++){
            allnode[i] = create(i);
        }
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
    void print(){
        for(int i = 0; i < 6; i++){
            int p = -1, l = -1, r = -1;
            if(allnode[i]->parent!=NULL)
                p = allnode[i]->parent->id;
            if(allnode[i]->left!=NULL)
                l = allnode[i]->left->id;
            if(allnode[i]->right!=NULL)
                r = allnode[i]->right->id;
            cout << "Node: " << i;
            cout << " parent: " << p;
            cout << " Left: " << l;
            cout << " Right: " << r << "\n";
        }
    }
};
int main(){
    BinaryTree bt;
    bt.build();
    bt.print();
}
