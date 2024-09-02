#include "Node.cpp"

// Approach 1
/*

bool isPali(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    vector<int> arr;
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        arr.push_back(temp->data);
    }
    int s = 0, e = arr.size() - 1;
    while (e > s)
    {
        if (arr[s++] != arr[e--])
        {
            return 0;
        }
    }
    return 1;
}
*/

// Approach 2

Node *reverse(Node *head)
{
    Node *curr = head, *prev = NULL;
    while (curr != NULL)
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}
bool isPali(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    Node *mid = slow;
    mid = reverse(mid);
    Node *temp1 = head, *temp2 = mid;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}
int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(10);
    Node *node4 = new Node(12);
    // Node *node5 = new Node(120);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node4->next = node5;

    print(head);
    if (isPali(head))
    {
        cout << "Palimdrome" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}