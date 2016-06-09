//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
class Solution {
public:
//time O(n), space(1)
//head should be reference parameter
TreeNode* sortedListToBST(ListNode*& head, int start, int end) {
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode *left = sortedListToBST(head, start, mid-1);
    TreeNode *root = new TreeNode(head->val);
    //trick let algo only traversal list once
    head = head->next;
    TreeNode *right= sortedListToBST(head, mid+1, end);
    root->left = left;
    root->right= right;
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int len = 0;
    ListNode *p = head;
    while (p) {
        p = p->next;
        len++;
    }
    return sortedListToBST(head, 0, len-1);
}
};
