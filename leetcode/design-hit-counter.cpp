// 362. Design Hit Counter
// https://leetcode.com/problems/design-hit-counter/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorials' Approach #2: Using Deque with Pairs
class HitCounter {
public:
    void hit(int timestamp) {
        if (hits.empty() || hits.back().first != timestamp)
            hits.emplace(pair<int, int>(timestamp, 1));
        else
            ++hits.back().second;
        ++total;
    }
    
    int getHits(int timestamp) {
        while (!hits.empty() && hits.front().first < timestamp - 299) {
            total -= hits.front().second;
            hits.pop();
        }
        return total;
    }

private:
    queue<pair<int, int>> hits;
    int total = 0;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
