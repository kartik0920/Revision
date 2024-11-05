#include "Node.cpp"

void postOrderRec(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderRec(root->left);
    postOrderRec(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    postOrderRec(root);
    return 0;
}