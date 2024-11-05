#include "Node.cpp"

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

Node *solve(vector<int> pre, vector<int> in, int n, unordered_map<int, int> mapping, int &preIndex, int s, int e)
{
    if (s > e || preIndex >= n)
    {
        return NULL;
    }
    int ele = pre[preIndex++];
    int pos = mapping[ele];
    Node *root = new Node(ele);
    root->left = solve(pre, in, n, mapping, preIndex, s, pos - 1);
    root->right = solve(pre, in, n, mapping, preIndex, pos + 1, e);
    return root;
}

Node *buildTree(vector<int> pre, vector<int> in, int n)
{
    unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++)
    {
        mapping[in[i]] = i;
    }
    int preIndex = 0, s = 0, e = n - 1;
    Node *ans = solve(pre, in, n, mapping, preIndex, s, e);

    return ans;
}

int main()
{
    Node *root = NULL;
    vector<int> pre = {3, 1, 4, 0, 5, 2};
    vector<int> in = {0, 1, 3, 4, 2, 5};
    int n = in.size();
    root = buildTree(pre, in, n);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
}