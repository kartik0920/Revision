#include "Node.cpp"
void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> topView(Node *root)
{
    map<int, int> mapping;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<Node *, int> front = q.front();
            q.pop();
            Node *frontNode = front.first;
            int hd = front.second;
            if (mapping.find(hd) == mapping.end())
            {
                mapping[hd] = frontNode->data;
            }
            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
    }
    for (auto i : mapping)
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

    printArr(topView(root));
    return 0;
}