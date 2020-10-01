#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *CreateTree()
{
    int v;
    cin >> v;

    if (v == -1)
    {
        return NULL;
    }
    node *root = new node(v);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "->";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root = CreateTree();
    preorder(root);
    return 0;
}