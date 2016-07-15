//https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
//Morris Traversal, space O(1)
void recoverTree(TreeNode* root) {
    TreeNode *pre = NULL, *cur = root, *tmp = NULL;
    vector<TreeNode*> v;
    while(cur){
        if(!cur->left){
            if(pre && pre->val > cur->val){
               v.push_back(pre);
               v.push_back(cur);
            }
            pre = cur;
            cur = cur->right;
        }else{
            tmp = cur->left;
            while(tmp->right && tmp->right != cur) tmp = tmp->right;
            if(tmp->right == NULL){
                tmp->right = cur;
                cur = cur->left;
            }else{
                tmp->right = NULL;
                if(pre && pre->val > cur->val){
                    v.push_back(pre);
                    v.push_back(cur);
                }
                pre = cur;
                cur = cur->right;
            }
        }
    }
    //the two nodes may be adjacent
    if(v.size() == 2) swap(v[0]->val, v[1]->val);
    if(v.size() == 4) swap(v[0]->val, v[3]->val);
}
};
