//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
// maintain a stack to store the index of heights, the height in the stack should be in ascending order.
// if the order is not ascending, pop the top one and caculate the area between the top one and current one.
// if the stack is not empty after traverse the height vector, caculate the area between the top one and the last one in height vector.

int largestRectangleArea(vector<int>& heights) {
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

//add a 0 in begining of stack as a guard to avoid judge whether the stack is empty.
int largestRectangleArea_1(vector<int>& heights) {
    stack<int> s;
    s.push(0);
    heights.insert(heights.begin(), 0);
    int res = 0, sz = heights.size();

    for(int i = 1; i < sz; ++i) {
        while(heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            res = max(res, height * (i - s.top() - 1));
        }
        s.push(i);
    }
    
    while(s.size() > 1) {
        int height = heights[s.top()];
        s.pop();
        res = max(res, height * (sz - s.top() - 1));
    }
    
    return res;
}
};
