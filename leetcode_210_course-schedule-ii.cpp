//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
//topological sort O(n+e)
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0), res;
    vector<vector<int>> courseNext(numCourses, vector<int>());
    for(int i = 0; i < prerequisites.size(); ++i){
        inDegree[prerequisites[i].first]++;
        courseNext[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    
    queue<int> zeroDegree;
    for(int i = 0; i < numCourses; ++i)
        if(inDegree[i] == 0) zeroDegree.push(i);
    
    while(!zeroDegree.empty()){
        int cur = zeroDegree.front();
        zeroDegree.pop();
        res.push_back(cur);
        for(int i = 0; i < courseNext[cur].size(); ++i){
            int next = courseNext[cur][i];
            inDegree[next]--;
            if(inDegree[next] == 0) zeroDegree.push(next);
        }
    }
    
    if(res.size() == numCourses) return res;
    return vector<int>();
}
};
