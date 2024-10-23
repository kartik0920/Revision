#include "node.cpp"
void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void getLeft(Node *root, vector<int> &arr)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    arr.push_back(root->data);
    if (root->left)
    {
        getLeft(root->left, arr);
    }
    else
    {
        getLeft(root->right, arr);
    }
}

void getLeaf(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        arr.push_back(root->data);
        return;
    }
    getLeaf(root->left, arr);
    getLeaf(root->right, arr);
}

void getRight(Node *root, vector<int> &arr)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right)
    {
        getRight(root->right, arr);
    }
    else
    {
        getRight(root->left, arr);
    }
    arr.push_back(root->data);
}

vector<int> verticalTravesal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    // left part;
    getLeft(root->left, ans);

    // leaf nodes
    getLeaf(root->left, ans);
    getLeaf(root->right, ans);

    // right nodes
    getRight(root->right, ans);

    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    vector<int> ans = verticalTravesal(root);
    printArr(ans);
    return 0;
}