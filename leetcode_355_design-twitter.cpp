//https://leetcode.com/problems/design-twitter/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        newsFeedNum = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(tweetId, userId));
        //make sure user can see userself's tweet
        usersFollower[userId].insert(userId);
        unordered_set<int>::iterator it = usersFollower[userId].begin();
        for(; it != usersFollower[userId].end(); it++){
            usersNewsFeed[*it].push_front(tweetId);
            if(usersNewsFeed[*it].size() > newsFeedNum){
                usersNewsFeed[*it].pop_back();
            }
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        deque<int> q = usersNewsFeed[userId];
        for(int i = 0; i < q.size(); ++i){
            res.push_back(q[i]);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        usersFollower[followeeId].insert(followerId);
        refreshNewsFeed(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        //user cannot unfollow userself
        if(followerId == followeeId) return;
        usersFollower[followeeId].erase(followerId);
        refreshNewsFeed(followerId);
    }
    
private:
    void refreshNewsFeed(int followerId){
        deque<int> tmp;
        for(int i = tweets.size()-1; i >= 0; --i){
            if(usersFollower[tweets[i].second].find(followerId) != usersFollower[tweets[i].second].end()){
                tmp.push_back(tweets[i].first);
            }
            if(tmp.size() == newsFeedNum) break;
        }
        usersNewsFeed[followerId] = tmp;
    }

    //tweets first is tweetId second is userId
    vector<pair<int,int>> tweets;
    unordered_map<int, deque<int>> usersNewsFeed;
    unordered_map<int, unordered_set<int>> usersFollower;
    int newsFeedNum;
};

/*
class Twitter {
public:
    Twitter() {
        newsFeedNum = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(tweetId, userId));
        //make sure user can see userself's tweet
        usersFollower[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(int i = tweets.size()-1; i >= 0; --i){
            if(usersFollower[tweets[i].second].find(userId) != usersFollower[tweets[i].second].end()){
                res.push_back(tweets[i].first);
            }
            if(res.size() == newsFeedNum) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        usersFollower[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        //user cannot unfollow userself
        if(followerId == followeeId) return;
        usersFollower[followeeId].erase(followerId);
    }
    
private:
    //tweets first is tweetId second is userId
    vector<pair<int,int>> tweets;
    unordered_map<int, deque<int>> usersNewsFeed;
    unordered_map<int, unordered_set<int>> usersFollower;
    int newsFeedNum;
};

*/

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
