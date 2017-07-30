/*
Given a sorted linked list, delete all duplicates such that each element appear
only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

ListNode *deleteDuplicates(ListNode *head) {
  if (head == NULL) {
    return head;
  }
  ListNode *tmp = head;
  while (tmp->next) {
    if (tmp->val == tmp->next->val) {
      tmp->next = tmp->next->next;
    } else {
      tmp = tmp->next;
    }
  }
  return head;
}