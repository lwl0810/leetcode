//https://leetcode.com/problems/russian-doll-envelopes/
bool mycomp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
int binarySearch(vector<pair<int, int>> v, int t) {
    int s = 0, e = v.size()-1, m = 0;
    while(s <= e) {
        m = (s + e) / 2;
        if (v[m].second >= t) e = m - 1;
        else s = m + 1;
    }
    return s;
}

//sort pair elements, compare by first, if first equal, sort the second in descencing order
//using binary search find the index in LIS array that greater or equal to the current element's second.
//time O(nlogn), space O(n)
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), mycomp);
    
    vector<pair<int,int>> LIS;
    for (int i = 0; i < envelopes.size(); ++i) {
        if (LIS.empty()) LIS.push_back(envelopes[i]);
        else {
            int idx = binarySearch(LIS, envelopes[i].second);
            if (idx < LIS.size()) LIS[idx] = envelopes[i];
            else LIS.push_back(envelopes[i]);
        }
    }
    return LIS.size();
}
};
