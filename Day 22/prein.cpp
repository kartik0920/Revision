#include "Node.cpp"

Node *solve(vector<int> in, vector<int> pre, int n, int &Preindex, int inStart, int inEnd, unordered_map<int, int> mapping)
{
    if (Preindex >= n || inStart > inEnd)
    {
        return NULL;
    }
    int ele = pre[Preindex++];
    int pos = mapping[ele];

    Node *root = new Node(ele);
    root->left = solve(in, pre, n, Preindex, inStart, pos - 1, mapping);
    root->right = solve(in, pre, n, Preindex, pos + 1, inEnd, mapping);

    return root;
}
Node *buildTree(vector<int> in, vector<int> pre, int n)

{
    int Preindex = 0;
    int inStart = 0, inEnd = n - 1;
    unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++)
    {
        mapping[in[i]] = i;
    }
    Node *ans = solve(in, pre, n, Preindex, inStart, inEnd, mapping);
    return ans;
}
int main()
{
    vector<int> in = {3, 1, 4, 0, 5, 2};
    vector<int> pre = {0, 1, 3, 4, 2, 5};
    int n = in.size();
    Node *root = NULL;
    root = buildTree(in, pre, n);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    return 0;
}