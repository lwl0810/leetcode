//http://www.cnblogs.com/jcliBlogger/p/4713099.html
/*
Meeting Rooms II
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

class Interval {
public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution{
public:
bool compare(Interval& a, Interval& b){
	return a.start < b.start;
}

//time O(nlogn), space O(n)
int minMeetingRooms(vector<Interval>& intervals){
	int minRooms = 0;
	priority_queue<int, vector<int>, greater<int>> inUse; //end time of inuse interval
	sort(intervals.begin(), intervals.end(), compare);
	for(int i = 0; i < intervals.size(); ++i){
		while(!inUse.empty() && inUse.top() <= intervals[i].start) inUse.pop();
		inUse.push(intervals[i].end);
		minRooms = max(minRooms, inUse.size());
	}
	return minRooms;
}
};
