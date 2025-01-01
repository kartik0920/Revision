#include "Node.cpp"

Node *getMax(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL && temp->right != NULL)
    {
        if (temp->right)
        {
            temp = temp->right;
        }
        else if (temp->left)
        {
            temp = temp->left;
        }
    }
    return temp;
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
    else if (root->data < x)
    {
        root->right = deleteNode(root->right, x);
        return root;
    }
    else
    {
        // case 1 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 1 2 childs
        if (root->left != NULL && root->right != NULL)
        {
            Node *maxi = getMax(root->left);
            root->data = maxi->data;
            root->left = deleteNode(root->left, maxi->data);
            return root;
        }
        // case 3 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
    }
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << ' ';
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    cout << endl;
    levelOrder(root);
    InOrder(root);
    cout << endl;
    int x = 5;

    root = deleteNode(root, x);
    cout << endl;
    levelOrder(root);
    InOrder(root);
}