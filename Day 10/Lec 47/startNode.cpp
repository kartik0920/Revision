#include "Node.cpp"

Node *isCycle(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *fast = head, *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (fast == slow)
        {
            return fast;
        }
    }
    return NULL;
}
Node *intersectionofLoop(Node *head)
{
    Node *inter = isCycle(head);
    Node *start = head;
    while (start != NULL && start != inter)
    {
        inter = inter->next;
        start = start->next;
    }
    return start;
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
    node5->next = node4;

    Node *intersection = intersectionofLoop(head);
    cout << intersection->data << endl;
    // cout << check << endl;
    return 0;
}