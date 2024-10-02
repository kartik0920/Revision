#include "Node.cpp"

Node *buildLevel(Node *root)
{
    int d;
    cout << "Enter root:";
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int l, r;
        cout << "Enter left of " << temp->data;
        cin >> l;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }
        cout << "enter right of " << temp->data;
        cin >> r;
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
}

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void reverseLevel(Node *root)
{
    queue<Node *> q;
    stack<vector<int>> st;
    st.push({root->data});
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        Node *front = q.front();
        q.pop();
        if (front->left)
        {
            temp.push_back(front->left->data);
        }
        if (front->right)
        {
            temp.push_back(front->right->data);
        }
        st.push(temp);
    }
    while (!st.empty())
    {
        printArr(st.top());
        st.pop();
    }
}
int main()
{

    Node *root = buildLevel(root);
    reverseLevel(root);
}