#include "Node.cpp"

void thisLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        if (front == NULL)
        {
            q.pop();
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }
        cout << front->data << " ";
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
        q.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    thisLevelOrder(root);
    return 0;
}