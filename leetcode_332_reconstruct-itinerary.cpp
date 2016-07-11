//https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
vector<string> findItinerary(vector<pair<string, string>> tickets){
    vector<string> res;
    unordered_map<string, deque<string>> um;
    stack<string> s;
    int n=tickets.size();
    for(int i=0; i<n; i++){
        string from=tickets[i].first, to=tickets[i].second;
        um[from].push_back(to);
    }
    for(unordered_map<string, deque<string>>::iterator it=um.begin(); it!=um.end(); it++)
        sort((it->second).begin(), (it->second).end());

    s.push("JFK");
    while(!s.empty()){
        string from=s.top();
        if(um[from].empty()){
			res.push_back(from);
			s.pop();
		}else{
			string to=um[from].front();
			s.push(to);
			um[from].pop_front();
		}
    }
	reverse(res.begin(), res.end());
    return res;
}

/*
bool dfs(vector<string>& res, unordered_map<string, map<string, int>>& flights, string cur, int ticketNum){
    if(res.size() == ticketNum+1) return true;
    for(map<string, int>::iterator it = flights[cur].begin(); it != flights[cur].end(); ++it){
        if(it->second == 0) continue;
        it->second--;
        res.push_back(it->first);
        if(dfs(res, flights, it->first, ticketNum)) return true;
        res.pop_back();
        it->second++;
    }
    return false;
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    int ticketNum = tickets.size();
    vector<string> res;
    //may have the same tickets !!!
    unordered_map<string, map<string, int>> flights;
    for(int i = 0; i < ticketNum; ++i){
        flights[tickets[i].first][tickets[i].second]++;
    }
    res.push_back("JFK");
    dfs(res, flights, "JFK", ticketNum);
    return res;
}
*/
};
