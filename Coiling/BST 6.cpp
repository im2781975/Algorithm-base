#include <bits/stdc++.h>
using namespace std;
//every Hd count based over root
// structure of the tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int item)
    {
        data = item;
        left = right = NULL;
    }
};
class BinaryTree {
public:
    Node* root;
    // Values class
    class Values {
    public:
        int max, min;
    };
    // Program to find vertical Order
    void verticalOrder(Node* node)
    {
        Values val;
        // Create TreeMap
        The key is the horizontal distance, and the value is a vector of node values at that distance.
        map<int, vector<int> > mp;
        // Function Call to findHorizontalDistance
        findHorizontalDistance(node, &val, &val, 0, mp);
        // Iterate over map.values()
        for (auto list : mp) {
            for (auto element : list.second) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
    // Program to find Horizontal Distance
    void findHorizontalDistance(Node* node, Values* min,
    Values* max, int hd, map<int, vector<int> >& mp)
    {
        // If node is null
        if (node == NULL)
            return;
        // if hd is less than min.min
        if (hd < min->min)
            min->min = hd;
        // if hd is greater than min.min
        if (hd > max->max)
            max->max = hd;
        // Using computeIfAbsent
        mp[hd].push_back(node->data);
 
        // Function Call with hd equal to hd - 1
        findHorizontalDistance(node->left, min, max, hd - 1, mp);
        // Function Call with hd equal to hd + 1
        findHorizontalDistance(node->right, min, max,
             hd + 1, mp);
    }
};
int main()
{
    BinaryTree tree;
 
    // Let us construct the tree shown in above diagram
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);
    tree.root->right->left->right = new Node(8);
    tree.root->right->right->right = new Node(9);
 
    cout << "vertical order traversal is :\n";
    tree.verticalOrder(tree.root);
    return 0;
}
