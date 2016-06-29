//https://leetcode.com/problems/flatten-nested-list-iterator/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        its.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        int res = (*(its.top())).getInteger();
        its.top()++;
        return res;
    }

    bool hasNext() {
        vector<NestedInteger>::iterator it;
        while(!its.empty()){
            it = its.top();
            if(it == ends.top()){
                its.pop();
                ends.pop();
                if(!its.empty()) its.top()++;
            }else{
                if((*it).isInteger()) break;
                else{
				    its.push((*it).getList().begin());
				    ends.push((*it).getList().end());
                }
            }
        }
        if(its.empty()) return false;
        return true;
    }
    
private:
    stack<vector<NestedInteger>::iterator> its;
    stack<vector<NestedInteger>::iterator> ends;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
