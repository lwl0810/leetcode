//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
//time O(log(m+n)) space O(1)
//find Kth number in two sorted arrays
//compare (k/2)th number in both nums1 and nums2, the array with smaller one should be cut
//pay attention to that an array may be empty and the k==1 is the exit of recursion
int getKthNumber(vector<int>& nums1, int s1, int n1, vector<int>& nums2, int s2, int n2, int k) {
    if(n1 < n2) return getKthNumber(nums2, s2, n2, nums1, s1, n1, k);
    if(n2 == 0) return nums1[s1 + k -1];
    if(k == 1) return min(nums1[s1], nums2[s2]);
    
    int k2 = min(n2, k / 2);
	int k1 = k - k2;
	if(nums1[s1 + k1 - 1] > nums2[s2 + k2 - 1])
		return getKthNumber(nums1, s1, k1, nums2, s2 + k2, n2 - k2, k - k2);
	return getKthNumber(nums1, s1 + k1, n1 - k1, nums2, s2, k2, k - k1);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    if((n1 + n2) % 2) 
        return getKthNumber(nums1, 0, n1, nums2, 0, n2, 1+(n1+n2)/2);
    return (getKthNumber(nums1, 0, n1, nums2, 0, n2, (n1+n2)/2) + getKthNumber(nums1, 0, n1, nums2, 0, n2, 1+(n1+n2)/2)) / 2.0;
}
};
