#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};



ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
	ListNode dummy(-1);
	int carry = 0;
	ListNode *prev = &dummy;
	for (ListNode *pa = l1,*pb = l2;
		pa != nullptr || pb != nullptr;
		pa = pa == nullptr ? nullptr : pa->next, pb = pb == nullptr ? nullptr : pb->next, prev = prev->next){

		const int ai = pa == nullptr ? 0 : pa->val;
		const int bi = pb == nullptr ? 0 : pb->val;
		const int value = (ai + bi + carry) % 10;
		cout << "this gets " << value << endl;
		carry = (ai + bi + carry) / 10;
		prev->next = new ListNode(value);
	}
	if (carry > 0){
		prev->next = new ListNode(carry);
	}
    
    return dummy.next;
	

	
}

void showListNode(ListNode *ld){
	while (NULL != ld){
		cout << ld->val << " ";
		ld = ld->next;
	}
}

int main(){
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