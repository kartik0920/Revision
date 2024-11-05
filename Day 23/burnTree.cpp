#include "Node.cpp"

Node *getTarget(Node *root, int target, unordered_map<Node *, Node *> &chiltToParent)
{
    Node *ans = NULL;
    queue<Node *> q;
    q.push(root);
    chiltToParent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            ans = front;
        }
        if (front->left)
        {
            q.push(front->left);
            chiltToParent[front->left] = front;
        }
        if (front->right)
        {
            q.push(front->right);
            chiltToParent[front->right] = front;
        }
    }
    return ans;
}

void solve(Node *targetNode, unordered_map<Node *, Node *> chiltToParent, int &ans)
{
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);
    while (!q.empty())
    {
        int size = q.size();
        bool check = 0;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                check = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                check = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            Node *parent = chiltToParent[front];
            if (parent && !visited[parent])
            {
                check = 1;
                q.push(parent);
                visited[parent] = 1;
            }
        }
        if (check)
        {
            ans++;
        }
    }
}

int burnTree(Node *root, int target)
{
    int ans = 0;
    unordered_map<Node *, Node *> chiltToParent;

    // STEP 1: CREATE MAPPING AND FINDINNG TARGET NODE

    Node *targetNode = getTarget(root, target, chiltToParent);

    solve(targetNode, chiltToParent, ans);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    int K = 1;
    cout << burnTree(root, K) << endl;
    return 0;
}