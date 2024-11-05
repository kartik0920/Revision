#include "Node.cpp"

pair<bool, int> solve(Node *root)
{
    // first--> bool  && second -->height
    if (root == NULL)
    {
        return {1, 0};
    }
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);
    bool check = abs(left.second - right.second) <= 1;
    bool first = left.first && right.first && check;
    int second = max(left.second, right.second) + 1;
    return {first, second};
}

bool isBalanced(Node *root)
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

    if (isBalanced(root))
    {
        cout << "Balaned" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}