#include "Node.cpp"

Node *buildTree1(Node *root)
{
    int data;
    cout << "Enter data";
    cin >> data;
    root = new Node(data);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        cout << "Enter on left of " << frontNode->data;
        cin >> data;
        if (data != -1)
        {
            Node *temp = new Node(data);
            frontNode->left = temp;
            q.push(temp);
        }
        cout << "Enter on right of " << frontNode->data;
        cin >> data;
        if (data != -1)
        {
            Node *temp = new Node(data);
            frontNode->right = temp;
            q.push(temp);
        }
    }
    return root;
}

void getInOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    getInOrder(root->left, arr);
    arr.push_back(root->data);
    getInOrder(root->right, arr);
}

bool isValid(Node *root)
{
    vector<int> arr;
    getInOrder(root, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return arr[0] > arr[arr.size() - 1] ? 0 : 1;
}

bool solve(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data > min && root->data < max)
    {
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);

        return (left & right);
    }
    else
    {
        return 0;
    }
}

bool isValid1(Node *root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return solve(root, min, max);
}

int main()
{
    Node *root = NULL;
    // root = buildTree1(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << isValid(root) << endl;
    cout << isValid1(root) << endl;
    return 0;
}
