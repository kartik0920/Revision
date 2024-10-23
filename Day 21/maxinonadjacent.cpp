#include "Node.cpp"

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int first = root->data + left.second + right.second;
    int second = max(left.first, left.second) + max(right.first, right.second);
    return {first, second};
}

int maxiSum(Node *root)
{

    // first ---> inclusion    second------>exclusion
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << maxiSum(root) << endl;
    return 0;
}