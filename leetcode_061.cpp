/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

// fast pointer forwards k step before slow pointer
// fast pointer run to the end, rearange the list

int getLen(ListNode *head) {
  int len = 0;
  ListNode *tmp = head;
  while (tmp) {
    len++;
    tmp = tmp->next;
  }
  return len;
}
ListNode *rotateRight(ListNode *head, int k) {
  if (head == NULL || k <= 0) {
    return head;
  }
  ListNode *fast = head;
  ListNode *slow = head;
  int run_left = k % getLen(head);
  if (run_left == 0) {
    return head;
  }
  while (run_left--) {
    fast = fast->next;
  }
  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }
  ListNode *pHead = slow->next;
  fast->next = head;
  slow->next = NULL;
  return pHead;
}