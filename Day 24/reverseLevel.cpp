#include "Node.cpp"

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void Reverse(Node *root)
{
    queue<Node *> q;
    stack<vector<int>> st;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            temp.push_back(front->data);
            q.pop();
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        st.push(temp);
    }
    while (!st.empty())
    {
        printArr(st.top());
        st.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    Reverse(root);
    return 0;
}