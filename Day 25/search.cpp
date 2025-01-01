#include "Node.cpp"

bool search(Node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == x)
    {
        return 1;
    }
    if (root->data < x)
    {
        search(root->right, x);
    }
    else
    {
        search(root->left, x);
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

    int x = 1;

    if (search(root, x))
    {
        cout << "PRESENT" << endl;
    }
    else
    {
        cout << "ABSENT" << endl;
    }
    return 0;
}