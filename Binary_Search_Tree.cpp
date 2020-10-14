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

node *InsertBst(node *root, int v)
{
    if (root == NULL)
    {
        return new node(v);
    }
    if (v > root->data)
    {
        root->right = InsertBst(root->right, v);
    }
    else
    {
        root->left = InsertBst(root->left, v);
    }
    return root;
}

void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " -> ";
    Inorder(root->right);
}

int main()
{
    int n, v;
    node *root = NULL;
    cin >> n;
    while (n--)
    {
        cin >> v;
        root = InsertBst(root, v);
    }
    Inorder(root);
    return 0;
}
