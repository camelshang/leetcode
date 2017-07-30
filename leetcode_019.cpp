/*
Given a linked list, remove the nth node from the end of list and return its
head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes
1->2->3->5.
*/

// O(2N-n)
int getLen(ListNode *head) {
  int len = 0;
  ListNode *tmp = head;
  while (tmp) {
    len++;
    tmp = tmp->next;
  }
  return len;
}
ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (n < 1 || head == NULL) {
    return head;
  }
  int len = getLen(head);
  if (n > len) {
    return head;
  }
  ListNode *dummy = new ListNode(-1);
  dummy->next = head;
  ListNode *tmp = dummy;
  int walk = len - n;
  while (walk) {
    walk--;
    tmp = tmp->next;
  }
  tmp->next = tmp->next->next;
  return dummy->next;
}

// O(n)
ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (n < 1 || head == NULL) {
    return head;
  }
  ListNode *dummy = new ListNode(-1);
  dummy->next = head;
  ListNode *f = dummy;
  ListNode *s = dummy;
  while (n--) {
    f = f->next;
  }
  while (f->next) {
    f = f->next;
    s = s->next;
  }
  s->next = s->next->next;
  return dummy->next;
}