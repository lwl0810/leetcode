//https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
//left[j] for j=0..n   means:for current pos j the left consecutive "1" length of row [0...i]
//right[j] for j=0..n   means:for current pos j the right consecutive "1" length of row [0...i]
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    int maxVal = 0;
    vector<int> height(n, 0), left(n, 0), right(n, n);
    for(int i = 0; i < m; ++i){
        int curleft = 0, curright = n;
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '1') left[j] = max(curleft, left[j]);
            else{
                left[j] = 0;
                curleft = j+1;
            }
        }
        for(int j = n-1; j >= 0; --j){
            if(matrix[i][j] == '1') right[j] = min(curright, right[j]);
            else{
                right[j] = n;
                curright = j;
            }
        }
        for(int j = 0; j < n; ++j){
            maxVal = max(maxVal, (right[j]-left[j])*height[j]);
        }
    }
    return maxVal;
}
/*
int maxAreaHistogram(vector<int>& heights) {
    stack<int> s;
    int res = 0, sz = heights.size();
    for(int i = 0; i < sz; ++i) {
        while(!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            if(s.empty()) res = max(res, height * i);
            else res = max(res, height*(i - s.top() - 1));
        }
        s.push(i);
    }
        
    while(!s.empty()) {
        int height = heights[s.top()];
        s.pop();
        if(s.empty()) res = max(res, height * sz);
        else res = max(res, height*(sz - s.top() - 1));
    }
        
    return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    int maxVal = 0;
    vector<int> heights(n, 0);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '0') heights[j] = 0;
            else heights[j]++;
        }
        maxVal = max(maxVal, maxAreaHistogram(heights));
    }
    return maxVal;
}
*/
};
