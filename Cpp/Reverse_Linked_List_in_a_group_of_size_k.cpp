#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int num;
  node *next;
  node(int a)
  {
    num = a;
    next = NULL;
  }
};

void insertNode(node *&head, int val)
{
  node *newNode = new node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }

  node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  return;
}

int lengthOfLinkedList(node *head)
{
  int length = 0;
  while (head != NULL)
  {
    ++length;
    head = head->next;
  }
  return length;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
  if (head == NULL || k == 1)
    return head;
  ListNode *dummy = new ListNode(0);
  dummy->next = head;
  ListNode *cur = dummy, *prev = dummy, *nex = dummy;
  int count = 0;
  while (cur->next != NULL)
  {
    cur = cur->next;
    count++;
  }
  while (count >= k)
  {
    cur = prev->next;
    nex = cur->next;
    for (int i = 1; i < k; i++)
    {
      cur->next = nex->next;
      nex->next = prev->next;
      prev->next = nex;
      nex = cur->next;
    }
    prev = cur;
    count -= k;
  }
  return dummy->next;
}

void printLinkedList(node *head)
{
  while (head->next != NULL)
  {
    cout << head->num << "->";
    head = head->next;
  }
  cout << head->num << "\n";
}

int main()
{
  node *head = NULL;
  int k = 3;
  insertNode(head, 1);
  insertNode(head, 2);
  insertNode(head, 3);
  insertNode(head, 4);
  insertNode(head, 5);
  insertNode(head, 6);
  insertNode(head, 7);
  insertNode(head, 8);

  cout << "Original Linked List: ";
  printLinkedList(head);
  cout << "After Reversal of k nodes: ";
  node *newHead = reverseKNodes(head, k);
  printLinkedList(newHead);

  return 0;
}