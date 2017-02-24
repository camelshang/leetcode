// reverse linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// iteration
ListNode *reverseList(ListNode *head) {
  ListNode *pre = NULL;
  while (head) {
    ListNode *next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

// recursive
ListNode *reverseList(ListNode *head) {
  if (head == NULL) {
    return null;
  } else if (head->next == NULL) {
    return head;
  } else {
    ListNode *newHead = reverseList(head->next);

    // reverse between head and head->next
    head->next->next = head;
    // unlink list from the rest
    head->next = NULL;

    return newHead;
  }
}