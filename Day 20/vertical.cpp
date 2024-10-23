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
    // hd---->level----->elemet
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> front = q.front();
        Node *frontnode = front.first;
        int hd = front.second.first;
        int lvl = front.second.second;
        nodes[hd][lvl].push_back(frontnode->data);
        q.pop();
        if (frontnode->left)
        {
            q.push({frontnode->left, {hd - 1, lvl + 1}});
        }
        if (frontnode->right)
        {
            q.push({frontnode->right, {hd + 1, lvl + 1}});
        }
    }
    vector<int> ans;
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
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