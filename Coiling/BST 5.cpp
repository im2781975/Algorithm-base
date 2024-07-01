#include <bits/stdc++.h>
typedef long long int lli;
typedef long long ll;
using namespace std;
// Structure for a binary tree node
struct Node {
    int data;
    Node *left, *right;
};
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// printing vertical order of a given binary tree using BFS
void printVerticalOrder(Node* root){
    if(root == NULL)
        return;
    // Create a map and store vertical order in map using function getVerticalOrder()
    unordered_map<int, vector<int> > m;
    int hd = 0;
    // queue do level order traversal which contains node and horizontal distance
    queue<pair<Node*, int> > q;
    q.push({ root, hd });
    // mn and mx contain the minimum and maximum horizontal distance from root
    int mn = 0, mx = 0;
    while (q.size() > 0) {
        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
        m[hd].push_back(node->data);
 
        if (node->left)
            q.push({ node->left, hd - 1 });
        if (node->right)
            q.push({ node->right, hd + 1 });
            
        if (mn > hd)
            mn = hd;
        else if (mx < hd)
            mx = hd;
    }
    // run the loop from minimum to maximum every horizontal distance hd
    for (int i = mn; i <= mx; i++) {
        vector<int> tmp = m[i];
        for (int j = 0; j < tmp.size(); j++)
            cout << tmp[j] << " ";
        cout << endl;
    }
}
// printing vertical order of a given binary tree
//hd of the root is taken as 0.For left child of any node, the hd =hd[node] -1.For the right child, hd = hd[node] +1
//Vertical distance starts from the root at level 1 and increments by 1 for each level down the tree.
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
            && (it->first >> 30) != maxi) {
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
    cout << "\nVertical order traversal is ";
    printVerticalOrder(root);
    cout << "\nVertical order traversal :- " << endl;
    verticalOrder(root);
    return 0;
}
