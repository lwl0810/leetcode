//https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        sz = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(um.find(val) != um.end()) return false;
        nums.push_back(val);
        um[val] = sz;
        ++sz;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(um.find(val) == um.end()) return false;
        int index = um[val];
        um.erase(val);
        if(index != sz-1){
            nums[index] = nums[sz-1];
            um[nums[index]] = index;
        }
        nums.pop_back();
        --sz;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(sz == 0) return INT_MIN;
        srand(time(NULL));
        int index = rand() % sz;
        return nums[index];
    }

private:
    int sz;
    unordered_map<int, int> um; //key: data, value: data's index in vector 
    vector<int> nums; //data
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
