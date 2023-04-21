// 355. Design Twitter
// https://leetcode.com/problems/design-twitter/

#include <bits/stdc++.h>

using namespace std;


// Optimized ideas are from https://leetcode.com/problems/design-twitter/solutions/3315416/simple-approach-with-explanation-using-priority-queues-and-unordered-maps/
class Twitter {
public:
    Twitter() {
        time = -1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(++time, tweetId);
        if (tweets[userId].size() > 10)
            tweets[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int, int>, greater<pair<int, int>>> news;
        for (const pair<int, int>& p: tweets[userId])
            news.emplace(p);
        for (const int& followeeId: following[userId]) {
            for (const pair<int, int>& p: tweets[followeeId]) 
                news.emplace(p);
        }
        
        vector<int> ans;
        set<pair<int, int>>::iterator news_it = news.begin();
        while (ans.size() < 10 && news_it != news.end()) {
            ans.emplace_back(news_it->second);
            ++news_it;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
    int time = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, list<pair<int, int>>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
