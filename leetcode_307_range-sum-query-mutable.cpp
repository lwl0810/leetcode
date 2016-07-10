//https://leetcode.com/problems/range-sum-query-mutable/

//time: initialize O(nlogn), update and query O(logn), space O(n)

/*
//Segment Tree Solution
class SegmentNode{
public:
    int start;
    int end;
    int sum;
    SegmentNode *left;
    SegmentNode *right;
    SegmentNode(int s, int e): start(s), end(e){sum = 0; left = NULL; right = NULL;}
};

class NumArray {
public:
NumArray(vector<int> &nums) {
    this->nums = nums;
    root = buildSegmentTree(0, nums.size()-1);
}

void update(int i, int val) {
    int diff = val - nums[i], mid = 0;
    SegmentNode *t = root;
    while(t->start != t->end){
        t->sum += diff;
        mid = (t->start + t->end) / 2;
        if(i <= mid) t = t->left;
        else t = t->right;
    }
    t->sum += diff;
    nums[i] = val; //never forget this line
}

int sumRange(int i, int j) {
    return sumRange(i, j, root);
}
    
private:
SegmentNode* buildSegmentTree(int start, int end){
    if(start > end) return NULL;
    SegmentNode *t = new SegmentNode(start, end);
    if(start == end) t->sum = nums[start];
    else{
        int mid = (start + end) / 2;
        t->left = buildSegmentTree(start, mid);
        t->right = buildSegmentTree(mid+1, end);
        t->sum = t->left->sum + t->right->sum;
    }
    return t;
}

int sumRange(int i, int j, SegmentNode* t){
    if(i == t->start && j == t->end) return t->sum;
    int mid = (t->start + t->end) / 2;
    if(j <= mid) return sumRange(i, j, t->left);
    else if(i > mid) return sumRange(i, j, t->right);
    else return sumRange(i, mid, t->left) + sumRange(mid+1, j, t->right);
}

vector<int> nums;
SegmentNode *root;
};
*/

//Binary Index Tree Solution
class NumArray {
public:
NumArray(vector<int> &nums) {
    sz = nums.size();
    this->nums.resize(sz, 0);
    binaryIndexTree.resize(sz+1, 0); //base 1, index 0 is useless
    for(int i = 0; i < sz; ++i) 
        update(i, nums[i]);
}

void update(int i, int val) {
    int diff = val - nums[i];
    nums[i] = val;
    i += 1;
    while(i <= sz){
        binaryIndexTree[i] += diff;
        i += i & (-i);
    }
}

//sum[1101]=tree[1101]+tree[1100]+tree[1000]
//sumRange(i, j) = sumRange(0, j+1) - sumRange(0, i)
int sumRange(int i, int j) {
    int sum_j = 0, sum_i = 0, k = j+1;
    while(k > 0){
        sum_j += binaryIndexTree[k];
        k -= k & (-k);
    }
    k = i;
    while(k > 0){
        sum_i += binaryIndexTree[k];
        k -= k & (-k);
    }
    return sum_j - sum_i;
}
    
private:
int sz;
vector<int> binaryIndexTree;
vector<int> nums;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
