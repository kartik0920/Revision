#include "Node.cpp"

bool isLoop(Node *head)
{
    Node *fast = head->next, *slow = head;

    while (fast != NULL)
    {
        if (fast == slow)
        {
            return 1;
        }
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return 0;
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
    node5->next = node3;

    if (isLoop(head))
    {
        cout << "Circular" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }

    return 0;
}