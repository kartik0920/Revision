#include "Node.cpp"

Node *removeDuplicate(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    unordered_map<int, int> mappping;
    Node *temp = head;

    while (temp != NULL)
    {
        int v = temp->data;
        mappping[v]++;
        temp = temp->next;
    }
    Node *ans;
    temp = head;
    while (temp != NULL)
    {
        int v = temp->data;
        if (mappping[v] > 1)
        {
        }
    }
    return ans;
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(100);
    Node *node2 = new Node(100);
    Node *node3 = new Node(124);
    Node *node4 = new Node(50);
    Node *node5 = new Node(6);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);
    Node *temp = removeDuplicate(head);
    print(temp);
    return 0;
}