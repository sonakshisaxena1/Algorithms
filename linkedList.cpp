#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }

};

Node* head;


void insert(int value, int pos)
{
    
    if(head == NULL)
    {
        head = new Node;
        head->next = NULL;
        head->data = value;
        return;
    }

    Node* x;
    x->data = value;
    int cnt = 1;
    if(pos == 1)
    {
        x->next = head;
        head = x;
    }
    else
    {
        Node* temp = head;
        int cnt = 1;
        while((cnt < pos) && (temp->next != NULL))
        {
            temp = temp->head;
            cnt++;
        }
        x->next = temp;
    }

    while(temp->next != NULL)
        temp = temp->next;
    
    x->next = NULL;
    temp->next = x;
    return;
}

void traverse()
{
    if(head == NULL)
    {
        cout << "Empty list!";
        return;
    }
    Node* temp = head;
    while((temp->next) != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    return;
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("test.out", "w", stdout);
    insert(1);
    insert(2);
    traverse();
    return 0;

}