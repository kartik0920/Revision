#include "Node.cpp"

void inOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int kthLargest(Node *root, int k)
{
    vector<int> arr;
    inOrder(root, arr);
    return arr[k - 1];
}

int solve(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = solve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return solve(root->right, i, k);
}

int kthSmallest1(Node *root, int k)
{
    int i = 0;
    return solve(root, i, k);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    int k = 2;
    cout << kthLargest(root, k) << endl;
    cout << kthSmallest1(root, k) << endl;

    return 0;
}
