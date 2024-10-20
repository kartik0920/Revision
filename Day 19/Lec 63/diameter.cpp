#include "Node.cpp"

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}
int diameter1(Node *root)
{

    // o(N^2) is complecty here
    if (root == NULL)
    {
        return 0;
    }
    int l = diameter1(root->left);
    int r = diameter1(root->right);
    int third = height(root->left) + height(root->right) + 1;
    return max(third, max(l, r));
}

pair<int, int> solve(Node *root)
{
    // first=height,second=diameter
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    pair<int, int> op1 = solve(root->left);
    pair<int, int> op2 = solve(root->right);
    int op3 = op1.first + op2.first + 1;
    pair<int, int> ans;
    ans.first = max(op1.first, op2.first) + 1;
    ans.second = max(op3, max(op2.second, op1.second));
    return ans;
}
int diameter2(Node *root)
{
    return solve(root).second;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << "Height of binary tree is : " << diameter1(root) << endl;
    cout << "Height of binary tree is : " << diameter2(root) << endl;
    return 0;
}