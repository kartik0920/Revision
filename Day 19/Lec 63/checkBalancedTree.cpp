#include "Node.cpp"

pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {1, 0};
    }
    pair<bool, int> op1 = solve(root->left);
    pair<bool, int> op2 = solve(root->right);
    if (abs(op1.second - op2.second) > 1)
    {
        return {0, -1};
    }

    pair<bool, int> ans;
    ans.first = op1.first && op2.first;
    ans.second = max(op1.second, op2.second) + 1;
    return ans;
}
bool isBalance(Node *root)
{
    return solve(root).first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    if (isBalance(root))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not balanced" << endl;
    }
    return 0;
}