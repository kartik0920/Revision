#include "Node.cpp"

Node *getMid(Node *head)
{

    // Approach 1
    /*
    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    temp = head;
    int index = 0;
    while (index < (i / 2))
    {
        temp = temp->next;
        index++;
    }
    return temp;
    */

    Node *slow = head, *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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
    Node *mid = getMid(head);
    print(mid);
    return 0;
}