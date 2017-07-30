// intersection of two linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if (headA == NULL || headB == NULL) {
    return NULL;
  }
  ListNode *p1 = headA;
  ListNode *p2 = headB;
  while (p1 != NULL && p2 != NULL && p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
    if (p1 == p2) {
      return p1;
    }
    if (p1 == NULL) {
      p1 = headB;
    }
    if (p2 == NULL) {
      p2 = headA;
    }
  }
  return p1;
}

// O(m+n)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if (headA == NULL || headB == NULL) {
    return NULL;
  }
  ListNode *cur1 = headA, *cur2 = headB;
  while (cur1 != cur2) {
    cur1 = cur1 ? cur1->next : headB;
    cur2 = cur2 ? cur2->next : headA;
  }
  return cur1;
}

// O(max(m,n))
int getLen(ListNode *head) {
  int len = 0;
  ListNode *tmp = head;
  while (tmp) {
    len++;
    tmp = tmp->next;
  }
  return len;
}

ListNode *getInt(ListNode *headA, int n1, ListNode *headB, int n2) {
  // n1 > n2
  int lendif = n1 - n2;
  ListNode *t1 = headA;
  ListNode *t2 = headB;
  while (lendif--) {
    t1 = t1->next;
  }
  while (t1 && t2) {
    if (t1 == t2) {
      return t1;
    }
    t1 = t1->next;
    t2 = t2->next;
  }
  return NULL;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if (headA == NULL || headB == NULL) {
    return NULL;
  }
  int n1 = getLen(headA);
  int n2 = getLen(headB);
  if (n1 > n2) {
    return getInt(headA, n1, headB, n2);
  } else {
    return getInt(headB, n2, headA, n1);
  }
}