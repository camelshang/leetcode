// merge two sorted litsts
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr) {
    return l2;
  }
  if (l2 == nullptr) {
    return l1;
  }
  if (l1->val < l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l2->next, l1);
    return l2;
  }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode *dummy = new ListNode(0);
  ListNode *tmp = dummy;
  while (l1 != NULL && l2 != NULL) {
    if (l1->val < l2->val) {
      tmp->next = l1;
      l1 = l1->next;
    } else {
      tmp->next = l2;
      l2 = l2->next;
    }
    tmp = tmp->next;
  }
  if (l1 != NULL)
    tmp->next = l1;
  else
    tmp->next = l2;
  return dummy->next;
}
