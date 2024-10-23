#include "Node.cpp"

void solve(Node *root, int k, int &cnt, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    arr.push_back(root->data);

    solve(root->left, k, cnt, arr);
    solve(root->right, k, cnt, arr);
    int sum = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        sum += arr[i];
        if (sum == k)
        {
            cnt++;
        }
    }
    arr.pop_back();
}

int ksumpath(Node *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    vector<int> arr;
    int cnt = 0;
    solve(root, k, cnt, arr);
    return cnt;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    int k = 6;
    cout << ksumpath(root, k) << endl;
    return 0;
}