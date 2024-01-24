#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int id;
    node* left;
    node* right;
    node* parent;
};

class Binary
{
public:
    node* root;
    node* allnode[7];
    Binary()
    {
        root = NULL;
    }

    node* create_newnode(int id)
    {
        node* newnode = new node;
        newnode->id = id;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        return newnode;
    }
    void build()
    {
        for (int i = 0; i < 7; i++)
            allnode[i] = create_newnode(i);

        allnode[0]->left = allnode[1];
        allnode[0]->right = allnode[2];
        allnode[1]->parent = allnode[0];
        allnode[2]->parent = allnode[0];
        allnode[1]->left = allnode[3];
        allnode[1]->right = allnode[4];
        allnode[3]->parent = allnode[1];
        allnode[4]->parent = allnode[1];
        allnode[2]->left = allnode[5];
        allnode[2]->right = allnode[6];
        allnode[5]->parent = allnode[2];
        allnode[6]->parent = allnode[2];

        root = allnode[0];
    }
    
    void insert(int id)
    {
        node* newnode = create_newnode(id);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        queue<node*> q;
        q.push(root);
        while (!q.empty())
        {
            node* a = q.front();
            q.pop();

            if (a->left != NULL)
                q.push(a->left);
            else
            {
                a->left = newnode;
                newnode->parent = a;
            }
            if (a->right != NULL)
                q.push(a->right);
            else
            {
                a->right = newnode;
                newnode->parent = a;
            }
        }
    }

    void BFS()
    {
        if (root == NULL)
            return;

        queue<node*> q;
        q.push(root);
        while (!q.empty())
        {
            node* a = q.front();
            q.pop();

            int p = -1, l = -1, r = -1;
            if (a->left != NULL)
            {
                l = a->left->id;
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                r = a->right->id;
                q.push(a->right);
            }
            if (a->parent != NULL)
                p = a->parent->id;
            cout << a->id << " " << l << " " << r << " " << p << "\n";
        }
    }
};
int main()
{
    Binary t;
    t.build();
    /*t.insert(1);
    t.insert(2);
    t.insert(3); */
    t.BFS();
    return 0;
}
