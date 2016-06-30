//http://www.cnblogs.com/grandyang/p/5626389.html
//Plus One Linked List
// 
//Given a non-negative number represented as a singly linked list of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.
//Example:
//Input:
//1->2->3
//Output:
//1->2->4

ListNode* reverse(ListNode *head){
	ListNode *dummy = new ListNode(0);
	ListNode *p = head;
	while(head){
		p = head;
		head = head->next;
		p->next = dummy->next;
		dummy->next = p;
	}
	return dummy->next;
}

ListNode* plusOne(ListNode* head){
	if(!head) return head;
	//reverse the linkedlist
	head = reverse(head);

	ListNode* p = head;
	int carry = 1, sum = 0;
	while(p && carry){
		sum = p->val + carry;
		p->val = sum % 10;
		carry = sum / 10;
		p = p->next;
	}

	head = reverse(head);
	if(carry){
		ListNode *one = new ListNode(1);
		one->next = head;
		head = one;
	}
	return head;
}
