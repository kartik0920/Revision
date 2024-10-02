
#include "Node.cpp"
Node *buildTree(Node *root)
{
    int d;
    cout << "Enter data:";
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    root = new Node(d);
    cout << "Enter left of " << root->data << ":";
    root->left = buildTree(root->left);
    cout << "Enter right of " << root->data << ":";
    root->right = buildTree(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // 1 2 -1 -1 3 -1 -1

    Node *root = buildTree(root);
    cout << "inorder Traversal:";
    inorder(root);
    cout << "\npreorder Traversal:";
    preorder(root);
    cout << "\npostorder Traversal:";
    postorder(root);
}
