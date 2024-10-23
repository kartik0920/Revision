#include "node.cpp"
void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> verticalTravesal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    bool check = 1;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            int index = check ? i : size - 1 - i;
            temp[index] = front->data;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        for (auto i : temp)
        {
            ans.push_back(i);
        }
        check = !check;
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    vector<int> ans = verticalTravesal(root);
    printArr(ans);
    return 0;
}