#include "Node.cpp"

Node *reverseK(Node *head, int k, int &len)
{
    if (len <= k)
    {
        return head;
    }
    if (head == NULL)
    {
        return head;
    }
    Node *curr = head, *prev = NULL, *fwd = head;
    int i = 0;
    while (curr != NULL && i < k)
    {
        i++;
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    // Node *temp = ;
    len -= k;

    head->next = reverseK(fwd, k, len);

    return prev;
}
int getlen(Node *head)
{
    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);
    int len = getlen(head);
    Node *ans = reverseK(head, 4, len);
    print(ans);
    return 0;
}