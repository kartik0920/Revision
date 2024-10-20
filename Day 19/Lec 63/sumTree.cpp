#include "Node.cpp"

pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {1, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data};
    }
    pair<bool, int> leftpart = solve(root->left);
    pair<bool, int> rightpart = solve(root->right);
    bool check = leftpart.second + rightpart.second == root->data;
    pair<bool, int> ans;
    ans.first = leftpart.first && rightpart.first && check;
    ans.second = root->data + leftpart.second + rightpart.second;
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
    cout << endl;
    if (isBalance(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    return 0;
}