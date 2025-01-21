#include "Node.cpp"

void printLL(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void inOrder(Node *root, vector<Node *> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root);
    inOrder(root->right, arr);
}

Node *flattend(Node *root)
{
    vector<Node *> arr;
    inOrder(root, arr);

    Node *curr = arr[0];
    Node *tail = curr;
    curr->left = NULL;

    for (int i = 1; i < arr.size(); i++)
    {

        tail->right = arr[i];
        tail = tail->right;
        tail->left = NULL;
    }
    return curr;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    Node *ll = flattend(root);
    printLL(ll);
    return 0;
}