#include "Node.cpp"

int getMin(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

Node *deleteBST(Node *root, int v)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data > v)
    {
        root->left = deleteBST(root->left, v);
        return root;
    }
    else if (root->data < v)
    {
        root->right = deleteBST(root->right, v);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int min = getMin(root->right);
            root->data = min;
            root->right = deleteBST(root->right, min);
            return root;
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    int val = 3;
    root = deleteBST(root, val);
    InOrder(root);
    return 0;
}