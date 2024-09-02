#include "Node.cpp"
Node *removedup(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    unordered_map<int, bool> mapping;
    mapping[head->data] = 1;
    Node *prev = head, *curr = head->next;
    while (curr != NULL)
    {
        if (mapping[curr->data])
        {
            curr = curr->next;
            prev->next = curr;
        }
        else
        {
            mapping[curr->data] = 1;
            curr = curr->next;
            prev = prev->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(00);
    Node *node3 = new Node(30);
    Node *node4 = new Node(10);
    Node *node5 = new Node(30);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);
    Node *t = removedup(head);
    print(t);
    return 0;
}