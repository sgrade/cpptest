// 1244. Design A Leaderboard
// https://leetcode.com/problems/design-a-leaderboard/

#include <bits/stdc++.h>

using namespace std;


class Leaderboard {
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        if (scores.find(playerId) != scores.end()) {
            top_scores.erase(pair<int, int>(scores[playerId], playerId));
        }
        scores[playerId] += score;
        top_scores.emplace(pair<int, int>(scores[playerId], playerId));
    }
    
    int top(int K) {
        int top_k_sum = 0;
        auto it = top_scores.begin();
        while (it != top_scores.end() && K--) {
            top_k_sum += it->first;
            ++it;
        }
        return top_k_sum;
    }
    
    void reset(int playerId) {
        if (scores.find(playerId) != scores.end()) {
            top_scores.erase(pair<int, int>(scores[playerId], playerId));
        }
        scores.erase(playerId);
    }

private:
    // player id -> score
    unordered_map<int, int> scores;
    // pair<score, playerid>
    set<pair<int, int>, greater<pair<int, int>>> top_scores;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
