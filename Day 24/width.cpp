#include "Node.cpp"

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int second = max(left.second, right.second) + 1;
    int op3 = left.second + right.second + 1;
    int first = max(op3, max(left.first, right.first));
    return {first, second};
}

int width(Node *root)
{

    // 1st == with 2nd ==height
    pair<int, int> ans = solve(root);
    return ans.first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << width(root) << endl;
    ;
    return 0;
}