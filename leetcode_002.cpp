/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode dummy(-1);
  int carry = 0;
  ListNode *prev = &dummy;
  for (ListNode *pa = l1, *pb = l2; pa != nullptr || pb != nullptr;
       pa = pa == nullptr ? nullptr : pa->next,
                pb = pb == nullptr ? nullptr : pb->next, prev = prev->next) {

    const int ai = pa == nullptr ? 0 : pa->val;
    const int bi = pb == nullptr ? 0 : pb->val;
    const int value = (ai + bi + carry) % 10;
    cout << "this gets " << value << endl;
    carry = (ai + bi + carry) / 10;
    prev->next = new ListNode(value);
  }
  if (carry > 0) {
    prev->next = new ListNode(carry);
  }

  return dummy.next;
}

ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
  ListNode dummy(-1);
  ListNode *phead = &dummy;
  int carry = 0;
  while (l1 || l2 || carry) {
    if (l1) {
      carry += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      carry += l2->next;
      l2 = l2->next;
    }
    phead->next = new ListNode(carry % 10);
    carry /= 10;
    phead = phead->next;
  }
  return dummy.next; // dummy not pointer, so use dot t access its member
}

void showListNode(ListNode *ld) {
  while (NULL != ld) {
    cout << ld->val << " ";
    ld = ld->next;
  }
}

int main() {
  ListNode *l1_1 = new ListNode(1);
  ListNode *l1_2 = new ListNode(8);
  ListNode *l1_3 = new ListNode(9);
  l1_1->next = l1_2;
  l1_2->next = l1_3;

  ListNode *l2_1 = new ListNode(0);

  ListNode *sum = addTwoNumbers(l1_1, l2_1);
  showListNode(l1_1);
  cout << endl;
  showListNode(l2_1);
  cout << endl;
  showListNode(sum);
  return 0;
}