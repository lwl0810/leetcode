//https://leetcode.com/problems/word-ladder-ii/

class Solution {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<vector<string>> res;
    //key: previous word, value: next word
    unordered_map<string, vector<string>> steps;
    unordered_set<string> q1, q2;
    bool isBegin = true, isFound = false;;
    q1.insert(beginWord);
    q2.insert(endWord);
    
    int cnt = 1;
    while(!q1.empty()){
        cnt++;
        unordered_set<string> q;
        //erase all the middle words must be here !!
        for(unordered_set<string>::iterator it = q1.begin(); it != q1.end(); ++it) wordList.erase(*it);
        for(unordered_set<string>::iterator it = q1.begin(); it != q1.end(); ++it){
            for(int i = 0; i < (*it).length(); ++i){
                string cur = *it;
                for(int j = 0; j < 26; ++j){
                    cur[i] = j + 'a';
                    if(wordList.find(cur) != wordList.end()){
                        if(isBegin) steps[*it].push_back(cur);
                        else steps[cur].push_back(*it);
                        q.insert(cur);
                        if(q2.find(cur) != q2.end()) isFound = true;
                    }
                }
            }
        }
        if(isFound) break;
        q1 = q;
        if(q1.size() > q2.size()){
            swap(q1, q2);
            isBegin = isBegin ? false: true;
        }
    }
    
    if(!isFound) return res;
     
    res.resize(1, vector<string>(1, beginWord));
    while(--cnt > 0){
        vector<vector<string>> tmp;
        for(int i = 0; i < res.size(); ++i){
            string cur = res[i].back();
            for(int j = 0; j < steps[cur].size(); ++j){
                string next = steps[cur][j];
                if(cnt > 1 || next == endWord){
                    tmp.push_back(res[i]);
                    tmp.back().push_back(next);
                }
            }
        }
        res = tmp;
    }
    return res;
}
};
