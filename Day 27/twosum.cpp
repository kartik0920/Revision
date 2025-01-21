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

pair<int, int> twosum(Node *root, int x)
{
    vector<int> arr;
    inOrder(root, arr);

    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int sum = arr[s] + arr[e];
        if (sum == x)
        {
            return {arr[s], arr[e]};
        }
        else if (sum > x)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    return {-1, -1};
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    pair<int, int> ans = twosum(root, 9);

    cout << ans.first << " " << ans.second << endl;
    return 0;
}