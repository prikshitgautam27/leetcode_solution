class Twitter {
public:
//maps to create 
//followers → map of user → set of followees.

//tweets → map of user → list of (time, tweetId) pairs.
 int timestamp;
unordered_map<int, unordered_set<int>>followers;
unordered_map<int, vector<pair<int,int>>>tweets;

    Twitter() {
        timestamp=0;

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});


    }
    
    vector<int> getNewsFeed(int userId) {
        // follower tweets
        priority_queue<pair<int,int>>pq;
        // user tweets
        for(auto& tw:tweets[userId]){
            pq.push(tw);
        }
        // follower tweets
        for(auto f: followers[userId]){
            for(auto &tw: tweets[f]){
                pq.push(tw);
            }
        }

        vector<int > res;
      int     count=0;

        while(!pq.empty() && count<10){
                res.push_back(pq.top().second);
                pq.pop();
                count++;
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId== followeeId) return;
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].count(followeeId)) {
        followers[followerId].erase(followeeId);
    }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */