#include "Node.cpp"

bool search(Node *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == k)
    {
        return 1;
    }

    if (root->data > k)
    {
        return search(root->left, k);
    }
    else
    {
        return search(root->right, k);
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    int key = 39;

    cout << search(root, key) << endl;
    return 0;
}