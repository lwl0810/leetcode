//https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class TNode{
public:
    int val;
    int cnt; //num of node whose val <= cur->val
    TNode* left;
    TNode* right;
    TNode(int v): val(v), cnt(0){left = NULL; right = NULL;}
};

class Solution {
public:

//BST solution, time O(nlogn), space O(n), 89%
int insertTNode(TNode* cur, TNode* node, int t){
    if(cur->val < node->val){
        if(cur->right){
            return insertTNode(cur->right, node, cur->cnt + t + 1);
        }else{
            cur->right = node;
            t += cur->cnt + 1;
        } 
    }else{
        cur->cnt++;
        if(cur->left){
            return insertTNode(cur->left, node, t);
        }else{
            cur->left = node;
        }
    }
    return t;
}

vector<int> countSmaller(vector<int>& nums){
    int sz = nums.size();
    vector<int> res(sz, 0);
    if(sz == 0) return res;
    TNode *root = new TNode(nums[sz-1]);
    for(int i = sz-2; i >= 0; --i){
        TNode *node = new TNode(nums[i]);
        res[i] = insertTNode(root, node, 0);
    }
    return res;
}

/*
//binary search and insert sort, time O(nlogn), space O(n), 50%
int binarySearch(vector<int>& sorts, int target){
    int start = 0, end = sorts.size()-1, mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(sorts[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

vector<int> countSmaller(vector<int>& nums) {
    int sz = nums.size();
    vector<int> sorts, res(sz, 0);
    if(sz == 0) return res;
    sorts.push_back(nums[sz-1]);
    for(int i = sz-2; i >= 0; --i){
        int idx = binarySearch(sorts, nums[i]);
        res[i] = idx;
        sorts.insert(sorts.begin()+idx, nums[i]);
        // vector<int>::iterator it = lower_bound(sorts.begin(), sorts.end(), nums[i]);
        // res[i] = distance(sorts.begin(), it);
        // sorts.insert(it, nums[i]);
    }
    return res;
}
*/

/*
//Binary Index Tree Solution, 29%
vector<int> countSmaller(vector<int>& nums) {
    int sz = nums.size();
    //key: nums[i], value: rank
    map<int, int> num2Rank;
    for(int i = 0; i < sz; ++i){
        num2Rank[nums[i]] = 0;
    }
    int idx = 0;
    for(map<int, int>::iterator it = num2Rank.begin(); it != num2Rank.end(); ++it){
        it->second = ++idx;
    }
    
    vector<int> res(sz, 0);
    vector<int> binaryIndexTree(idx+1, 0); //not sz+1, nums may contain duplicates
    for(int i = sz-1; i >= 0; --i){
        int rank = num2Rank[nums[i]];
        // update BIT
        for(int idx = rank; idx <= sz; idx += idx&(-idx))
            binaryIndexTree[idx] += 1;
        
        // read BIT
        int cnt = 0;
        for(int idx = rank-1; idx > 0; idx -= idx&(-idx))
            cnt += binaryIndexTree[idx];
            
        res[i] = cnt;
    }
    return res;
}
*/
};
