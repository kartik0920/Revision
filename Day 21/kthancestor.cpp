#include "Node.cpp"

Node *solve(Node *root, int n, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }

    Node *left = solve(root->left, n, k);
    Node *right = solve(root->right, n, k);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else if (right != NULL && left == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    else
    {
        return NULL;
    }
}

int kthanc(Node *root, int n, int k)
{
    Node *ans = solve(root, n, k);
    if (ans == NULL)
    {
        cout << "fuck";
    }
    if (ans == NULL || ans->data == n)
    {
        return -1;
    }
    return ans->data;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    int n = 4, k = 2;
    cout << kthanc(root, n, k) << endl;
    return 0;
}