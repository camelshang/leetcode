/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

ListNode *removeElements(ListNode *head, int val) {
  if (head == NULL) {
    return NULL;
  }
  ListNode *tmp = head;
  while (tmp->next) {
    if (tmp->next->val == val) {
      tmp->next = tmp->next->next;
    } else {
      tmp = tmp->next;
    }
  }

  if (head->val == val) {
    head = head->next;
  }

  return head;
}