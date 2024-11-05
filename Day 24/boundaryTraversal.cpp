#include "Node.cpp"

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void solveLeft(Node *root, vector<int> &arr)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    arr.push_back(root->data);
    if (root->left)
    {
        solveLeft(root->left, arr);
    }
    else
    {
        solveLeft(root->right, arr);
    }
}

void solveLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    solveLeaf(root->left, ans);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    solveLeaf(root->right, ans);
}

void solveRight(Node *root, vector<int> &ans)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    solveRight(root->right, ans);
    solveRight(root->left, ans);
    ans.push_back(root->data);
}
vector<int> boundayTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    solveLeft(root->left, ans);
    solveLeaf(root, ans);
    solveRight(root->right, ans);
    return ans;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    printArr(boundayTraversal(root));
    return 0;
}