#include "Node.cpp"

void getIn(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    getIn(root->left, arr);
    arr.push_back(root->data);
    getIn(root->right, arr);
}

int kthLargest(Node *root, int k)
{
    vector<int> arr;
    getIn(root, arr);
    return k >= arr.size() ? arr[arr.size() - 1] : arr[k - 1];
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << kthLargest(root, 2) << endl;
}