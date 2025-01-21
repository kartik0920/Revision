#include "Node.cpp"

int successor(Node *root, int key)
{
    int ans = -1;
    Node *temp = root;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            ans = temp->data;
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    temp = temp->right;

    while (temp != NULL)
    {
        ans = temp->data;
        temp = temp->left;
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

    cout << successor(root, 3) << endl;
    return 0;
}