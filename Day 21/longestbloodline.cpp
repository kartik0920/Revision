#include "Node.cpp"

void solve(Node *root, int len, int sum, int &maxlen, int &maxsum)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum += root->data;
    solve(root->left, len + 1, sum, maxlen, maxsum);
    solve(root->right, len + 1, sum, maxlen, maxsum);
}

int sumBloodline(Node *root)
{
    int sum = 0, maxsum = INT_MIN;
    int len = 0, maxlen = 0;

    solve(root, len, sum, maxlen, maxsum);
    return maxsum;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << sumBloodline(root) << endl;
    return 0;
}