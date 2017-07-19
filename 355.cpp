class Twitter {
public:
    /** Initialize your data structure here. */
    map< pair<int,int>, bool> fs;
    vector<pair<int,int>> feed;
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        feed.push_back(make_pair(userId,tweetId));
        fs[make_pair(userId,userId)]=true;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        int num=0;
        for(int i=feed.size()-1;i>=0;i--){
            if(fs.count(make_pair(userId,feed[i].first))){
                if(fs[make_pair(userId,feed[i].first)]){
                    ret.push_back(feed[i].second);
                    num++;
                    if(num==10) return ret;
                }
            }
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        fs[make_pair(followerId,followeeId)]=true;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        fs[make_pair(followerId,followeeId)]=false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
