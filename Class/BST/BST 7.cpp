// printing vertical order of a given binary tree
//hd of the root is taken as 0.For left child of any node, the hd =hd[node] -1.For the right child, hd = hd[node] +1
//Vertical distance starts from the root at level 1 and increments by 1 for each level down the tree.
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long long ll;
struct Node {
    int data;
    Node *left, *right;
};
struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void preOrderTraversal(Node* root, lli hd, lli vd,
    map<lli, vector<int> >& m){
    if (!root)
        return;
    // key = horizontal, distance (30 bits) + vertical, distance (30 bits) map will store key in sorted order.
    //Thus nodes having same horizontal distance will sort according to vertical distance.
    // By left-shifting hd by 30 bits and performing a bitwise OR with vd, 
    ll val = hd << 30 | vd;
    m[val].push_back(root->data);
    preOrderTraversal(root->left, hd - 1, vd + 1, m);
    preOrderTraversal(root->right, hd + 1, vd + 1, m);
}
void verticalOrder(Node* root)
{
    // map to store all nodes in vertical order. keys will be horizontal + vertical distance.
    map<lli, vector<int> > mp;
    preOrderTraversal(root, 0, 1, mp);
    int maxi= INT_MAX;
    map<lli, vector<int> >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (maxi != INT_MAX
            && (it->first >> 30) != prekey) {
            cout << endl;
        }
        maxi = it->first >> 30;
        for (int j = 0; j < it->second.size(); j++)
            cout << it->second[j] << " ";
    }
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal :- " << endl;
    verticalOrder(root);
    return 0;
}
