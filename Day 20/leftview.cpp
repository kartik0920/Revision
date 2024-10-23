#include "node.cpp"
void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> rightview1(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        int x;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (i == 0)
            {
                x = front->data;
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        ans.push_back(x);
    }
    return ans;
}

void solve(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }

    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}

vector<int> rightview2(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    vector<int> ans1 = rightview1(root);
    vector<int> ans2 = rightview2(root);
    printArr(ans1);
    printArr(ans2);
    return 0;
}