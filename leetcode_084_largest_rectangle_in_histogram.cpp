class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> heightidx;
        int res = 0, sz = heights.size();
        for(int i = 0; i < sz; ++i) {
            while(!heightidx.empty() && heights[i] < heights[heightidx.top()]) {
                int height = heights[heightidx.top()];
                heightidx.pop();
                if(heightidx.empty()) res = max(res, height * i);
                else res = max(res, height*(i - heightidx.top() - 1));
            }
            heightidx.push(i);
        }
        
        while(!heightidx.empty()) {
            int height = heights[heightidx.top()];
            heightidx.pop();
            if(heightidx.empty()) res = max(res, height * sz);
            else res = max(res, height*(sz - heightidx.top() - 1));
        }
        
        return res;
    }
};
