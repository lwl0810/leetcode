//https://leetcode.com/problems/data-stream-as-disjoint-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        //find the smallest start greater or equal to val
        int idx = binarySearch(val);
        //no previous and next interval, just insert the [val,val]
        if(intervals.empty()){
            intervals.push_back(Interval(val,val));
            return;
        }
        
        if(idx > 0){
            //val is included in previous interval, no change
            if(intervals[idx-1].end >= val) return;
            //val is equal to the previous interval end +1
            if(intervals[idx-1].end == val-1){
                intervals[idx-1].end = val;
                //previous interval is the final interval
                if(idx == intervals.size()) return;
            }
            //val is greater than the previous interval's end+1 and the previous interval is the final interval
            //just insert the [val,val] at the end of intervals
            if(intervals[idx-1].end < val-1 && idx == intervals.size()){
                intervals.push_back(Interval(val,val));
                return;
            }
        }
        
        if(idx < intervals.size()){
            //val is included in next interval, no change
            if(intervals[idx].start == val) return;
            //val is equal to the next interval start -1
            if(intervals[idx].start == val+1){
                intervals[idx].start = val;
                //next interval is the first interval
                if(idx == 0) return;
            }
            //val is smaller than the previous interval's start-1 and the next interval is the first interval
            //just insert the [val,val] at the beginning of intervals
            if(intervals[idx].start > val+1 && idx == 0){
                intervals.insert(intervals.begin(), Interval(val,val));
                return;
            }
        }
        
        //insert [val,val] does not cause any merge, just insert
        if(intervals[idx-1].end != val && intervals[idx].start != val){
            intervals.insert(intervals.begin()+idx, Interval(val,val));
            return;
        }
        
        //deal with the merge
        if(intervals[idx-1].end >= intervals[idx].start-1){
            intervals[idx-1].end = intervals[idx].end;
            intervals.erase(intervals.begin()+idx);
        }
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }

private:
    int binarySearch(int target) {
        int l = 0, r = intervals.size()-1, m = 0;
        while(l <= r){
            m = (l + r) / 2;
            if(target == intervals[m].start) return m;
            else if(target > intervals[m].start) l = m+1;
            else r = m-1;
        }
        return l;
    }

    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
