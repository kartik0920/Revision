#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << ' ';
    }
    cout << endl;
}
