//
/*
Design Phone Directory
Design a Phone Directory which supports the following operations:
    get: Provide a number which is not assigned to anyone.
    check: Check if a number is available or not.
    release: Recycle or release a number.

Example:
// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
		maxNum = maxNumbers;
		num = 0;
		recycleIdx = -1;
		recycle.resize(maxNum);
		isAssigned.resize(maxNum, false);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
		if(num == maxNum && recycleIdx == -1) return -1;
		if(recycleIdx != -1) {
			isAssigned[recycleIdx] = true;
			--recycleIdx;
			return recycle[recycleIdx+1];
		}
		isAssigned[num] = true;
		return num++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
		if(number >= 0 && number < maxNum && isAssigned[number] == false)
			return true;
		return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
		if(number < 0 || number >= maxNum || isAssigned[number] == false)
			return;
		recycle[++recycleIdx] = number;
		isAssigned[number] = false;
    }
    
private:
	vector<int> recycle;		//maintain the recycled num
	vector<bool> isAssigned;  	//mark the assigned status
	int num;			//the current available num
	int recycleIdx;			//the index of current available recycled num
	int maxNum;
};
