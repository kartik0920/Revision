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

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << endl
         << endl
         << endl;
    printTree(root);
}