//https://leetcode.com/problems/reverse-nodes-in-k-group/
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
//time O(n), space O(1)
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(0);
    ListNode *p = head, *tail = dummy;
    int cnt = 0;
    while(p) {
        cnt = 0;
        ListNode *tmp = new ListNode(0);
        ListNode *newtail = NULL;
        while(p && cnt < k) {
            ListNode *q = p;
            if(cnt == 0) newtail = q;
            p = p->next;
            q->next = tmp->next;
            tmp->next = q;
            cnt++;
        }
        if(cnt == k) {
            tail->next = tmp->next;
            tail = newtail;
        }else {
            p = tmp->next;
            tmp->next = NULL;
            while(p) {
                ListNode *q = p;
                p = p->next;
                q->next = tmp->next;
                tmp->next = q;
            }
            tail->next = tmp->next;
        }
    }
    return dummy->next;
}
};
