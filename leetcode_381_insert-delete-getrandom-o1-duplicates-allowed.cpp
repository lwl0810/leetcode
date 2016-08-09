//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = um.find(val) == um.end()? false: true;
        int sz = vec.size();
        um[val].insert(sz);
        vec.push_back(val);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(um.find(val) == um.end()) return false;
        int index = *(um[val].begin());
        
        //remove val's index from map
        um[val].erase(index);
        if(um[val].empty()) um.erase(val);
        
        //remove val from vector
        int sz = vec.size();
        if(index != sz-1) {
            vec[index] = vec[sz-1];
            um[vec[index]].erase(sz-1);
            um[vec[index]].insert(index);
        }
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int sz = vec.size();
        if(sz == 0) return INT_MIN;
        int index = rand() % sz;
        return vec[index];
    }
    
private:
    //key: val, value: val's index in vector 
    unordered_map<int, unordered_set<int>> um;
    //maintain the vals
    vector<int> vec;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
