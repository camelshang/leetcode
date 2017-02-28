// palindrome linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(n)  O(1)
bool isPalindrome(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return true;
  }
  ListNode *mid = findmid(head);
  mid->next = reverse(mid->next);
  mid = mid->next;
  while (head != NULL && mid != NULL) {
    if (head->val != mid->val) {
      return false;
    }
    head = head->next;
    mid = mid->next;
  }
  return true;
}

ListNode *findmid(ListNode *now) { // 快指针走完，慢指针刚还位于中间位置
  ListNode *slow = now;
  ListNode *fast = now->next;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode *reverse(ListNode *now) {
  ListNode *pre = NULL;
  while (now != NULL) {
    ListNode *temp = now->next;
    now->next = pre;
    pre = now;
    now = temp;
  }
  return pre;
}

// O(n) O(1) SAME AS METHOD ABOVE
bool isPalindrome(ListNode *head) {
  if (head == NULL || head->next == NULL)
    return true;
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != NULL && fast->next->next != NULL) { // slow指针为中间位置
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = reverseList(slow->next);
  slow = slow->next;
  while (slow != NULL) {
    if (head->val != slow->val)
      return false;
    head = head->next;
    slow = slow->next;
  }
  return true;
}
ListNode *reverseList(ListNode *head) {
  ListNode *pre = NULL;
  ListNode *next = NULL;
  while (head != NULL) {
    next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

// O(n) O(n)
bool isPalindrome(ListNode *head) {
  if (!head || !head->next)
    return true;
  ListNode *slow = head, *fast = head;
  stack<int> s;
  s.push(head->val);
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    s.push(slow->val);
  }
  if (!fast->next)
    s.pop();
  while (slow->next) { //将存储在栈中的前半段与后半段进行对比
    slow = slow->next;
    int tmp = s.top();
    s.pop();
    if (tmp != slow->val)
      return false;
  }
  return true;
}
