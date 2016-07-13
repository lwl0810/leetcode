//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:

//O(logn)
// Adds a number into the data structure.
void addNum(int num) {
    if(larger.empty() || num < larger.top())smaller.push(num);
    else larger.push(num);
    if(smaller.size() - 1 > larger.size()){
        larger.push(smaller.top());
        smaller.pop();
    }
    if(smaller.size() + 1 < larger.size()){
        smaller.push(larger.top());
        larger.pop();
    }
    
}

//O(1)
// Returns the median of current data stream
double findMedian() {
    double res = 0;
    if(smaller.size() == larger.size()) res = ((double)(smaller.top() + larger.top())) / 2;
    else res = smaller.size() > larger.size() ? smaller.top() : larger.top();
    return res;
}
    
private:
priority_queue<int> smaller;
priority_queue<int, vector<int>, greater<int>> larger;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
