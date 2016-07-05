//https://leetcode.com/problems/add-and-search-word-data-structure-design/

class TrieNode{
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode(){isWord = false; for(int i = 0; i < 26; ++i) children[i] = NULL;}
};

class WordDictionary {
public:
WordDictionary(){
    root = new TrieNode();
}

// Adds a word into the data structure.
void addWord(string word) {
    TrieNode *t = root;
    for(int i = 0; i < word.length(); ++i){
        char ch = word[i];
        if(t->children[ch-'a'] == NULL){
            t->children[ch-'a'] = new TrieNode();
        }
        if(i == word.length()-1){
            t->children[ch-'a']->isWord = true;
        }
        t = t->children[ch-'a'];
    }
}

// Returns if the word is in the data structure. A word could
// contain the dot character '.' to represent any one letter.
bool search(string word) {
    return search(word, root);
}

private:
TrieNode *root;
    
bool search(string word, TrieNode* t){
    if(word.length() == 0) return t->isWord != NULL;
    if(word[0] != '.'){
        if(t->children[word[0]-'a'] == NULL) return false;
        return search(word.substr(1), t->children[word[0]-'a']);
    }
    for(int i = 0; i < 26; ++i){
        if(t->children[i] != NULL){
            if(search(word.substr(1), t->children[i])) return true;
        }
    }
    return false;
}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
