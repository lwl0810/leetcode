//https://leetcode.com/problems/create-maximum-number/

class Solution {
public:
//total time O(k*n^2), space O(m+n)

//time O(k*n)
void maxNum(vector<int>& nums, vector<int>& v, int k){
    int i = 0, n = nums.size();
    while(k){
        int j = i, maxVal = -1, maxPos = -1;
        while(n - j >= k){
            if(nums[j] > maxVal){
                maxVal = nums[j];
                maxPos = j;
            }
            ++j;
        }
        i = maxPos+1;
        v.push_back(maxVal);
        k--;
    }
}

//time O(n^2)
void merge(vector<int>& v, vector<int>& v1, vector<int>& v2){
    int n1 = v1.size(), n2 = v2.size(), i = 0, j = 0;
    while(i < n1 && j < n2){
        if(v1[i] > v2[j]) v.push_back(v1[i++]);
        else if(v1[i] < v2[j]) v.push_back(v2[j++]);
        else {
            int k = 1;
            while(i+k < n1 && j+k < n2 && v1[i+k] == v2[j+k]) ++k;
            if(i+k < n1 && j+k < n2){
                if(v1[i+k] > v2[j+k]) v.push_back(v1[i++]);
                else v.push_back(v2[j++]);
            }else if(i+k == n1) v.push_back(v2[j++]);
            else v.push_back(v1[i++]);
        }
    }
    while(i < n1) v.push_back(v1[i++]);
    while(j < n2) v.push_back(v2[j++]);
}

//time O(n)
bool compare(vector<int>& v1, vector<int>& v2){
    for(int i = 0; i < v1.size(); ++i){
        if(v1[i] < v2[i]) return true;
        if(v1[i] > v2[i]) return false;
    }
    return false;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> res(k, 0);
    for(int i = 0; i <= k; ++i){
        if(i > n1 || k-i > n2) continue;
        vector<int> v1, v2, v;
        maxNum(nums1, v1, i);
        maxNum(nums2, v2, k-i);
        merge(v, v1, v2);
        if(compare(res, v)) res = v;
    }
    return res;
}
};

//TLE
// class Num{
// public:
//     int num, p1, p2;
//     Num():num(0), p1(0), p2(0){}
//     Num(Num* n):num(n->num), p1(n->p1), p2(n->p2){}
// };

// class Solution {
// public:
// int nextNumber(vector<int>& nums, Num* num, int who, int k){
//     int otherSize = who == 1? n2-num->p2: n1-num->p1;
//     int needSize = k - otherSize;
//     int p = who == 1? num->p1: num->p2;
//     int maxNum = -1, maxPos = -1, n = who == 1? n1: n2;
//     while(p < n && n-p > needSize){
//         if(nums[p] > maxNum){
//             maxNum = nums[p];
//             maxPos = p;
//         }
//         p++;
//     }
//     if(who == 1) num->p1 = maxPos+1;
//     else num->p2 = maxPos+1;
//     num->num = num->num*10 + maxNum;
//     return maxNum;
// }

// vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//     n1 = nums1.size(); 
//     n2 = nums2.size();
//     vector<int> res;
//     queue<Num*> q;
//     Num *num = new Num();
//     q.push(num);
//     while(--k >= 0){
//         queue<Num*> tmp;
//         int curMaxNum = -1;
//         while(!q.empty()){
//             Num* cur = q.front();
//             q.pop();
//             if(cur->p1 < n1){
//                 Num* num1 = new Num(cur);
//                 curMaxNum = max(curMaxNum, nextNumber(nums1, num1, 1, k));
//                 while(!tmp.empty() && tmp.front()->num < num1->num) tmp.pop();
//                 if(tmp.empty() || tmp.front()->num == num1->num) tmp.push(num1);
//             }
//             if(cur->p2 < n2){
//                 Num* num2 = new Num(cur);
//                 curMaxNum = max(curMaxNum, nextNumber(nums2, num2, 2, k));
//                 while(!tmp.empty() && tmp.front()->num < num2->num) tmp.pop();
//                 if(tmp.empty() || tmp.front()->num == num2->num) tmp.push(num2);
//             }
//         }
//         res.push_back(curMaxNum);
//         q = tmp;
//     }
//     return res;
// }

// private:
//     int n1, n2;
// };
