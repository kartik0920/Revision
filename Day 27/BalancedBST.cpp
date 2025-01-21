#include "Node.cpp"

void inOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

Node *getBst(int s, int e, vector<int> arr)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    Node *root = new Node(arr[mid]);

    root->left = getBst(s, mid - 1, arr);
    root->right = getBst(mid + 1, e, arr);

    return root;
}

Node *heightBalance(Node *root)
{
    vector<int> arr;
    inOrder(root, arr);

    int s = 0, e = arr.size() - 1;
    return getBst(s, e, arr);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    InOrder(heightBalance(root));
    return 0;
}