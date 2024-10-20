#include "Node.cpp"

bool identical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
    {
        return 0;
    }

    if (root1->data != root2->data)
    {
        return 0;
    }
    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);
    return left && right;
}

int main()
{
    Node *root1 = NULL;
    root1 = buildTree(root1);
    Node *root2 = NULL;
    root2 = buildTree(root2);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << endl;
    if (identical(root1, root2))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }
    return 0;
}