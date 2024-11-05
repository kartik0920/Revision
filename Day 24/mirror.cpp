#include "Node.cpp"

Node *mirrorTree(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *ans = root;
    queue<Node *> q, q2;
    q.push(root);
    q2.push(ans);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front1 = q.front();
            Node *front2 = q2.front();
            q.pop();
            q2.pop();
            if (front1->left)
            {
                front2->right = new Node(front1->left->data);
                q.push(front1->left);
                q2.push(front2->right);
            }
            if (front1->right)
            {
                front2->left = new Node(front1->right->data);
                q.push(front1->right);
                q2.push(front2->left);
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

    Node *temp = mirrorTree(root);
    LevelOrder(temp);
    return 0;
}