#include "Node.cpp"

pair<Node *, Node *> split(Node *head)
{
    if (head == NULL || head->next == head)
    {

        return {head, NULL};
    }
    Node *slow = head, *fast = head->next;
    while (fast->next != head)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next == head)
        {
            break;
        }
        fast = fast->next;
    }
    fast->next = slow->next;
    Node *second = slow->next;
    // cout << slow->data << "22" << endl;
    slow->next = head;
    return {head, second};
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    // Node *node5 = new Node(50);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = head;
    // node5->next = head;
    print(head);
    pair<Node *, Node *> t = split(head);
    print(t.first);
    print(t.second);
    return 0;
}