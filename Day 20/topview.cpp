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
    //
    map<int, int> nodes;
    // hd---->nodes
    queue<pair<int, Node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        pair<int, Node *> front = q.front();
        Node *frontnode = front.second;
        int hd = front.first;
        q.pop();

        if (nodes.find(hd) == nodes.end())
        {
            nodes[hd] = frontnode->data;
        }

        if (frontnode->left)
        {
            q.push({hd - 1, frontnode->left});
        }
        if (frontnode->right)
        {
            q.push({hd + 1, frontnode->right});
        }
    }

    for (auto i : nodes)
    {
        ans.push_back(i.second);
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
    vector<int> ans = rightview1(root);
    printArr(ans);
    return 0;
}