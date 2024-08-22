#include "Node.cpp"

void removeDuplicate(Node *head)
{

    Node *temp = head, *curr = head;
    while (curr != NULL)
    {
        if (curr->data != temp->data)
        {
            temp->next = curr;
            temp = curr;
            curr = curr->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    temp->next = NULL;
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(1);
    Node *node3 = new Node(1);
    Node *node4 = new Node(50);
    Node *node5 = new Node(60);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);
    removeDuplicate(head);
    print(head);
    return 0;
}