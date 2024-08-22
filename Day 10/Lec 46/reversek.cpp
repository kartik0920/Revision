#include "Node.cpp"

Node *reverseK(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    Node *fwd, *curr = head, *prev = NULL;
    int i = 0;
    while (curr != NULL && i < k)
    {
        i++;
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    head->next = reverseK(fwd, k);
    return prev;
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
    int k = 3;
    Node *t = reverseK(head, k);
    print(t);
    return 0;
}