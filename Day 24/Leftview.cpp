#include "Node.cpp"

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> leftViewiterative(Node *root)
{
    vector<int> ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        bool check = 0;
        int temp;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (!check)
            {
                temp = front->data;
            }
            check = 1;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

void solve(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }
    if (ans.size() == lvl)
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    int lvl = 0;
    solve(root, ans, lvl);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    printArr(leftViewiterative(root));
    printArr(leftView(root));
    return 0;
}