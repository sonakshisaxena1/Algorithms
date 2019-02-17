//Recursive Approach

#include <bits/stdc++.h> 
using namespace std; 


struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int data): val(data), next(NULL){}
};

ListNode* head = new ListNode(-1);



ListNode* reverseK(ListNode* head, int k)
{

  ListNode* curr = head;
  ListNode* prev = NULL;
  ListNode* ahead = NULL;
  int cnt = 0;
  while(curr != NULL && cnt < k)
  {
    ahead = curr->next;
    curr->next = prev;
    prev = curr;
    curr = ahead;
    cnt++;
  }

  if(ahead != NULL)
    head->next = reverseK(ahead, k);

  return prev;
  

}

void insert(int x)
{
  
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
    for(int i = 0; i < 4; i++)
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
    cout << "\n";
    head = reverseK(head, 2);
    printList();
    return 0;

} 