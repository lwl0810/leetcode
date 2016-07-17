//https://leetcode.com/problems/text-justification/

class Solution {
public:
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int sz = words.size(), i = 0; 
    bool isEnd = false;
    while(i < sz){
        int width = words[i].length(), wordNum = 1;
        while(i+wordNum < sz){
            if(width + 1 + words[i+wordNum].length() > maxWidth) break;
            width += 1 + words[i+wordNum].length();
            wordNum++;
        }
        if(i+wordNum == sz){
            isEnd = true;
        }
        //pay attention wordNum == 1 may cause spaceNum = 0
        int spaceNum = wordNum==1? 1: wordNum-1, spaces = maxWidth-width+spaceNum;
        int remainder = spaces % spaceNum, spaceWidth = spaces / spaceNum;
        string cur = words[i++]; wordNum--;
        while(wordNum){
            int spaceLen = isEnd? 1: (spaceWidth + (remainder>0? 1: 0));
            string space(spaceLen, ' ');
            cur += space + words[i++];
            remainder--;
            wordNum--;
        }
        //add space after the final word to reach maxWidth
        while(cur.length() < maxWidth) cur += " ";
        res.push_back(cur);
    }
    return res;
}
};
