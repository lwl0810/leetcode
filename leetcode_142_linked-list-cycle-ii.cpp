//https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
//time O(n) space O(1)
ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    ListNode *fast = head, *slow = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
        if(slow == fast) break;
    }
    if(fast == NULL) return NULL;
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
};
