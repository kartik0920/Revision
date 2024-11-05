#include "Node.cpp"

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        int temp;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
            temp = front->data;
        }
        ans.push_back(temp);
    }
    return ans;
}

void solve(Node *root, vector<int> &arr, int lvl)
{
    if (root == NULL)
    {
        return;
    }
    if (arr.size() == lvl)
    {
        arr.push_back(root->data);
    }
    solve(root->right, arr, lvl + 1);
    solve(root->left, arr, lvl + 1);
}

vector<int> rightViewRucc(Node *root)
{
    int lvl = 0;
    vector<int> arr;
    solve(root, arr, lvl);
    return arr;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    printArr(rightView(root));
    printArr(rightViewRucc(root));
    return 0;
}