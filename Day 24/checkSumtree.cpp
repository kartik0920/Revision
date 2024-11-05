#include "Node.cpp"

pair<bool, int> solve(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data};
    }
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    int sum = left.second + right.second;
    bool check = sum == root->data;

    bool firsts = 0;
    if (check && left.first && right.first)
    {
        firsts = 1;
    }
    int second = 2 * root->data;
    return {firsts, second};
}

bool checkSumtree(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return solve(root).first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    if (checkSumtree(root))
    {
        cout << "Sum" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}