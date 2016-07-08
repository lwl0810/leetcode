//https://leetcode.com/problems/word-ladder/

class Solution {
public:
//time O(V*26*len) or O(2*(b^(d/2))
int biDirectionBFS(unordered_set<string>& q1, unordered_set<string>& q2, unordered_set<string>& wordList){
    int cnt = 1;
    while(!q1.empty()){
        cnt++;
        unordered_set<string> q;
        for(unordered_set<string>::iterator it = q1.begin(); it != q1.end(); ++it){
            for(int i = 0; i < (*it).length(); ++i){
                string cur = *it;
                for(int j = 0; j < 26; ++j){
                    cur[i] = j + 'a';
                    if(q2.find(cur) != q2.end()){
                        return cnt;
                    }
                    if(wordList.find(cur) != wordList.end()){
                        wordList.erase(cur);
                        q.insert(cur);
                    }
                }
            }
        }
        if(q.size() < q2.size()) q1 = q;
        else{q1 = q2; q2 = q;}
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    unordered_set<string> q1, q2;
    q1.insert(beginWord);
    q2.insert(endWord);
    wordList.erase(beginWord);
    wordList.erase(endWord);
    return biDirectionBFS(q1, q2, wordList);
}
};
