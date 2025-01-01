#include "Node.cpp"

bool solve(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);
        return left && right;
    }
    else
        return 0;
}

bool validate1(Node *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

void getIn(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    getIn(root->left, arr);
    arr.push_back(root->data);
    getIn(root->right, arr);
}
bool validate2(Node *root)
{
    vector<int> arr;
    getIn(root, arr);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return arr[0] < arr[arr.size() - 1] ? 1 : 0;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << validate1(root);
    cout << endl;
    cout << validate2(root);
    cout << endl;
}