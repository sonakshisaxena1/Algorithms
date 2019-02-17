//Iterative Approcah

#include <bits/stdc++.h> 
using namespace std; 


struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int data): val(data), next(NULL){}
};

ListNode* head = new ListNode(-1);

void reverse()
{
  ListNode* curr = head;
  ListNode* prev = NULL;
  ListNode* ahead = NULL;
  while(curr != NULL)
  {
    ahead = curr->next;
    curr->next = prev;
    prev = curr;
    curr = ahead;

  }
  head = prev;
}


void insert(int x)
{
  // if(head == NULL)
  // {
  //   head->val = x;
  //   head->next = NULL;
  //   return;
  // }
  
  ListNode* curr = head;
  while(curr->next != NULL)
  {
    curr = curr->next;
  }
  ListNode* temp = new ListNode(x);
  curr->next = temp;
  return;
}
 

void printList()
{
  if(head == NULL)
    cout << "List Empty";
  else
  {
    ListNode* curr = head;
    while(curr != NULL)
    {
      cout << curr->val << " ";
      curr = curr->next;
    }
  }
  return;
}
int main() 
{ 
    
  	freopen("test.in", "r", stdin);
  	freopen("test.out", "w", stdout);
    int x;
    for(int i = 0; i < 5; i++)
    {
      cin >> x;
      if(i == 0)
      {
        head->val = x;
        head->next = NULL;
        continue;
      }
      insert(x);
    }

    printList();
    reverse();
    cout << "\n";
    printList();
    return 0;

} 