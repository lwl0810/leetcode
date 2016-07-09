//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class mycomp{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first+a.second < b.first+b.second;
    }
};

class Solution {
public:
//time O((n^2)*logk) space O(k)
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int>> res;
    //pop greatest elem in the pq
    priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp> pq;
    for(int i = 0; i < nums1.size(); ++i){
        for(int j = 0; j < nums2.size(); ++j){
            pq.push(make_pair(nums1[i], nums2[j]));
            if(pq.size() > k) pq.pop();
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
};
