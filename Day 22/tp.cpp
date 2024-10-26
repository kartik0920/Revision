#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int> &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node *root)
{
    vector<int> v;
    queue<Node *> q;

    q.push(root);

    Node *next_row = NULL;

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if (n == next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left)
        {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right)
        {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/

// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution
{
public:
    pair<int, int> solve(vector<int> arr, int d)
    {
        int first = -1, second = -1;
        bool check = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == d && check)
            {
                arr[i] = -1;
                first = i;
                check = 0;
            }
            if (arr[i] == d && first != -1)
            {
                second = i;
                arr[i] = -1;
            }
        }
        return {first, second};
    }
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> arr)
    {

        Node *root;
        int n = arr.size();

        // finding root
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                root = new Node(i);
            }
        }
        if (arr.size() == 1)
        {
            return root;
        }

        // mapping the elements
        unordered_map<int, pair<int, int>> mapping;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                continue;
            }

            mapping[arr[i]] = solve(arr, arr[i]);
        }

        // creating tree by level order
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                pair<int, int> lr = mapping[front->data];
                if (mapping.find(front->data) != mapping.end())
                    mapping[front->data] = {-1, -1};
                if (lr.first != -1)
                {
                    cout << "First" << lr.first << endl;
                    front->left = new Node(lr.first);
                    q.push(front->left);
                }
                if (lr.second != -1)
                {
                    front->right = new Node(lr.second);
                    q.push(front->right);
                }
                q.pop();
            }
        }
        return root;
    }
};

int main()
{

    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    Solution ob;

    Node *res = ob.createTree(a);

    printLevelOrder(res);
    cout << endl;

    return 0;
}