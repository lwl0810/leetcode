//https://leetcode.com/problems/course-schedule/

class Solution {
public:
//find circle recursion dfs
/*
bool dfs(vector<vector<int>>& courses, int cur, vector<int>& visit){
    int next = 0;
    visit[cur] = 1;
    for(int i = 0; i < courses[cur].size(); ++i){
        next = courses[cur][i];
        if(visit[next] == 1) return false;
        if(visit[next] == 2) continue;
        if(!dfs(courses, next, visit)) return false;
    }
    visit[cur] = 2;
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> courses(numCourses, vector<int>());
    vector<int> visit(numCourses, 0);
    for(int i = 0; i < prerequisites.size(); ++i){
        courses[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    for(int i = 0; i < numCourses; ++i){
        if(visit[i] != 0) continue;
        if(!dfs(courses, i, visit)) return false;
    }
    return true;
}
*/


//find circle dfs iteration
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> courses(numCourses, vector<int>());
    vector<int> visit(numCourses, 0);
    for(int i = 0; i < prerequisites.size(); ++i){
        courses[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    stack<int> s;
    for(int i = 0; i < numCourses; ++i){
        if(visit[i]) continue;
        s.push(i);
        visit[i] = 1;
        int cur = 0, next = 0, j = 0;
        while(!s.empty()){
            cur = s.top();
            for(j = 0; j < courses[cur].size(); ++j){
                next = courses[cur][j];
                if(visit[next] == 1) return false;
                if(visit[next] == 2) continue;
                s.push(next);
                visit[next] = 1;
                break;
            }
            if(j == courses[cur].size()){ 
                visit[cur] = 2;
                s.pop();
            }
        }
    }
    return true;
}

};
