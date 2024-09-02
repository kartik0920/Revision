#include "Node.cpp"

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

void addTail(Node *&tail, int data)
{
    tail->next = new Node(data);
    tail = tail->next;
}

Node *add1(Node *head)
{
    int carry = 0;
    Node *ans = new Node(-1);
    Node *tail = ans;
    Node *c = reverse(head);
    Node *temp = c;
    while (temp != NULL)
    {

        int a = temp->data;
        int sum = a + carry;
        if (temp == c)
        {
            sum++;
        }
        addTail(tail, sum % 10);
        carry = sum / 10;
        temp = temp->next;
    }

    while (carry != 0)
    {
        addTail(tail, carry % 10);
        carry /= 10;
    }
    ans = ans->next;
    return reverse(ans);
}
int main()
{
    Node *head = new Node(9);
    Node *node1 = new Node(9);
    Node *node2 = new Node(9);
    Node *node3 = new Node(9);
    // Node *node4 = new Node(4);
    // Node *node5 = new Node(9);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    print(head);

    Node *t = add1(head);
    print(t);

    return 0;
}