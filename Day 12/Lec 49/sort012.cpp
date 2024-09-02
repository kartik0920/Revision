#include "Node.cpp"

// Aprroach 1
/*
Node *sort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int zero = 0, one = 0, two = 0;
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        if (zero != 0)
        {
            zero--;
            temp->data = 0;
        }
        else if (one != 0)
        {
            one--;
            temp->data = 1;
        }
        else
        {
            temp->data = 2;
        }
    }
    return head;
}
*/
// Approach 2
void addT(Node *&tail, int data)
{
    tail->next = new Node(data);
    tail = tail->next;
}
Node *sort(Node *head)
{
    Node *oneH = new Node(-1);
    Node *twoH = new Node(-1);
    Node *zeroH = new Node(-1);
    Node *zeroT = zeroH, *oneT = oneH, *twoT = twoH;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            addT(zeroT, 0);
        }
        else if (temp->data == 1)
        {
            addT(oneT, 1);
        }
        else
        {
            addT(twoT, 2);
        }
        temp = temp->next;
    }

    if (oneH->next == NULL)
    {
        zeroT->next = twoH->next;
        return zeroH;
    }
    zeroT->next = oneH->next;
    oneT->next = twoH->next;
    zeroH = zeroH->next;
    return zeroH;
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(2);
    Node *node4 = new Node(1);
    Node *node5 = new Node(2);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);

    Node *t = sort(head);
    print(t);
    return 0;
}