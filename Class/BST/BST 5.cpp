#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST {
    private:
    Node* root;
    Node* insertRec(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }
        return root;
    }
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node* deleteRec(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->data) {
            root->left = deleteRec(root->left, value);
        } else if (value > root->data) {
            root->right = deleteRec(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }
    bool searchRec(Node* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (value == root->data) {
            return true;
        } else if (value < root->data) {
            return searchRec(root->left, value);
        } else {
            return searchRec(root->right, value);
        }
    }
    public:
    BST() : root(nullptr) {}
    void insert(int value) {
        root = insertRec(root, value);
    }
    void deleteValue(int value) {
        root = deleteRec(root, value);
    }
    bool search(int value) {
        return searchRec(root, value);
    }
};
int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "\nSearch for 40: " << (bst.search(40) ? "Found" : "Not found") ;
    cout << "\nSearch for 90: " << (bst.search(90) ? "Found" : "Not found") ;

    bst.deleteValue(30);
    cout << "\nSearch for 30 after deletion: " << (bst.search(30) ? "Found" : "Not found") ;
    return 0;
}
