#include "Node.cpp"

Node *LCA(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data > p && root->data > q)
    {
        return LCA(root->left, p, q);
    }
    if (root->data < p && root->data < q)
    {
        return LCA(root->right, p, q);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << LCA(root, 3, 2)->data << endl;
    return 0;
}