class Twitter {
    // use vector<pair<int,int>> to represent the catalog of recent tweets 
    // use unordered_map<int, unordered_map<int, int>> to store each user's following list 
    vector<pair<int,int>> catalog; // store userId, tweet
    unordered_map<int, unordered_map<int, int>> users; // store userId, following list
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        catalog.push_back({userId, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        // returns 10 most recent tweet IDs on the feed of the user userID
        vector<int> res; 
        auto following = users[userId]; // following is a map 
        int count = 0; 
        auto it = catalog.end(); 
        while (count < 10) 
        {
            auto temp = *it; 
            if (following.contains(temp.first) || userId == temp.first)
            {
                res.push_back(temp.second);
                count++; 
            }
            if (it == catalog.begin()) break;
            it--; 
        }
        return res; 
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId][followeeId]++; 
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId); 
    }
};
