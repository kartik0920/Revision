#include "Node.cpp"

Node *LCA(Node *root, int x, int y)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x || root->data == y)
    {
        return root;
    }
    Node *left = LCA(root->left, x, y);
    Node *right = LCA(root->right, x, y);

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    else if (left != NULL && right == NULL)
    {
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        return right;
    }
    else
    {
        return root;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << LCA(root, 3, 6)->data << endl;
    return 0;
}