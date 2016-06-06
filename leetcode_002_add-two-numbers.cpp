//https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//avoid allocate memeory for new node
//time O(n), space O(1)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    int addone = 0, sum = 0;
    while(l1 && l2) {
        sum = l1->val + l2->val + addone;
        if(sum > 9) {
            addone = 1;
            sum -= 10;
        } else addone = 0;
        l1->val = sum;
        p->next = l1;
        p = p->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(l2) l1 = l2;
    p->next = l1;
    while(addone && p->next) {
        sum = p->next->val + addone;
        if(sum > 9) {
            addone = 1;
            sum -= 10;
        } else addone = 0;
        p->next->val = sum;
        p = p->next;
    }
    
    if(addone == 1) p->next = new ListNode(1);
    
    return dummy->next;
}
};
