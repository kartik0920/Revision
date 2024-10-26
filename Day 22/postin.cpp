#include "Node.cpp"

Node *solve(vector<int> in, vector<int> post, int n, int &postIndex, int inStart, int inEnd, unordered_map<int, int> mapping)
{
    if (postIndex < 0 || inStart > inEnd)
    {
        return NULL;
    }
    int ele = post[postIndex--];
    int pos = mapping[ele];

    Node *root = new Node(ele);
    root->right = solve(in, post, n, postIndex, pos + 1, inEnd, mapping);
    root->left = solve(in, post, n, postIndex, inStart, pos - 1, mapping);

    return root;
}

Node *buildTree(vector<int> in, vector<int> post, int n)
{
    int postIndex = n - 1;
    int inStart = 0, inEnd = n - 1;
    unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++)
    {
        mapping[in[i]] = i;
    }

    return solve(in, post, n, postIndex, inStart, inEnd, mapping);
}
int main()
{
    vector<int> in = {3, 1, 4, 0, 5, 2};
    vector<int> post = {0, 1, 3, 4, 2, 5};
    int n = in.size();
    Node *root = NULL;
    root = buildTree(in, post, n);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    return 0;
}