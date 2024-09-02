#include "Node.cpp"

Node *reverse(Node *head)
{
    Node *prev = NULL, *curr = head;
    while (curr != NULL)
    {

        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

void insertTail(Node *&tail, int data)
{
    tail->next = new Node(data);
    tail = tail->next;
}

Node *add(Node *l1, Node *l2)
{
    Node *ans = new Node(-1);
    Node *tail = ans;
    Node *temp1 = l1, *temp2 = l2;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int a = temp1->data;
        int b = temp2->data;
        int sum = a + b + carry;
        insertTail(tail, sum % 10);
        carry = sum / 10;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        int a = temp1->data;
        int sum = a + carry;
        insertTail(tail, sum % 10);
        carry = sum / 10;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        int a = temp2->data;
        int sum = a + carry;
        insertTail(tail, sum % 10);
        carry = sum / 10;
        temp2 = temp2->next;
    }
    while (carry != 0)
    {
        insertTail(tail, carry % 10);
        carry = carry / 10;
    }
    return ans->next;
}

Node *add2(Node *head1, Node *head2)
{
    int carry = 0;
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node *ans = add(head1, head2);
    return reverse(ans);
}
