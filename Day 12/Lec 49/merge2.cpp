#include "Node.cpp"

Node *solve(Node *l1, Node *l2)
{
    if (l1->next == NULL)
    {
        l1->next = l2;
        return l1;
    }
    Node *curr1 = l1;
    Node *curr2 = l2;
    Node *next1 = curr1->next;
    while (next1 != NULL && curr2 != NULL)
    {

        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            curr2 = curr2->next;
            curr1->next->next = next1;
            curr1 = curr1->next;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1->next == NULL)
            {
                next1->next = curr2;
                break;
            }
        }
    }
    return l1;
}
Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data <= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(55);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Node *head1 = new Node(0);
    Node *node11 = new Node(10);
    Node *node21 = new Node(11);
    Node *node31 = new Node(30);
    Node *node41 = new Node(45);
    Node *node51 = new Node(50);
    head1->next = node11;
    node11->next = node21;
    node21->next = node31;
    node31->next = node41;
    node41->next = node51;
    print(head);
    print(head1);

    Node *t = merge(head1, head);
    print(t);
    return 0;
}