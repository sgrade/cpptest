// 1244. Design A Leaderboard
// https://leetcode.com/problems/design-a-leaderboard/

#include <bits/stdc++.h>

using namespace std;


class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        scores[playerId] += score;
        max_heap.emplace(pair<int, int>(scores[playerId], playerId));
    }
    
    int top(int K) {
        int top_k_sum = 0;
        int cnt = 0;
        queue<pair<int, int>> temp;
        while (!max_heap.empty() && cnt < K) {
            pair<int, int> p = max_heap.top();
            max_heap.pop();
            if (scores[p.second] != p.first)
                continue;
            ++cnt;
            top_k_sum += p.first;
            temp.emplace(p);
        }
        while (!temp.empty()) {
            max_heap.emplace(temp.front());
            temp.pop();
        }
        return top_k_sum;
    }
    
    void reset(int playerId) {
        scores[playerId] = 0;
    }

private:
    // player id to score
    unordered_map<int, int> scores;
    // pair<score, playerid>
    priority_queue<pair<int, int>> max_heap;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */