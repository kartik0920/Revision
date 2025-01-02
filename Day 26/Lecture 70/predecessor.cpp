#include "Node.cpp"

Node *getNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == x)
    {
        return root;
    }
    else if (root->data > x)
    {
        return getNode(root->left, x);
    }
    else
    {
        return getNode(root->right, x);
    }
}

int getMax(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        cout << temp->data;
        temp = temp->right;
    }
    return temp->data;
}

int predecessor(Node *root, int key)
{
    int ans = -1;
    // Node* keyNode=NULL;
    while (root->data != key)
    {
        int d = root->data;
        if (d > key)
        {
            root = root->left;
        }
        else
        {
            ans = d;
            root = root->right;
        }
    }
    root = root->left;
    while (root != NULL)
    {
        ans = root->data;
        root = root->right;
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << predecessor(root, 3) << endl;
    return 0;
}