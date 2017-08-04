/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in
the list, only nodes itself can be changed.
*/

ListNode *swapPairs(ListNode *head) {
  ListNode *dummy = new ListNode(-1);
  dummy->next = head;
  ListNode *pNext;
  ListNode *tmp = dummy;
  while (tmp->next != NULL && tmp->next->next != NULL) {
    pNext = tmp->next;

    tmp->next = pNext->next;
    pNext->next = tmp->next->next;
    tmp->next->next = pNext;

    tmp = pNext;
  }
  return dummy->next;
}