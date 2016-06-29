//http://www.cnblogs.com/grandyang/p/5450001.html
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size);
    double next(int val);

private:
	int winsize;
	double sum; 
	queue<int> q;
};

MovingAverage::MovingAverage(int size){
	winsize = size;
	sum = 0;
}

double MovingAverage::next(int val){
	if(q.size() == winsize){
		sum -= q.front();
		q.pop();
	}
	q.push(val);
	sum += val;
	return sum / q.size();
}
