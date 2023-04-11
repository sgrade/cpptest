// 362. Design Hit Counter
// https://leetcode.com/problems/design-hit-counter/

#include <bits/stdc++.h>

using namespace std;


class HitCounter {
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        ++hits[timestamp];
        while (!hits.empty() && hits.begin()->first < timestamp - 300 + 1) {
            hits.erase(hits.begin());
        }
    }
    
    int getHits(int timestamp) {
        int current_timestamp = hits.begin()->first;
        while (!hits.empty() && hits.begin()->first < timestamp - 300 + 1) {
            hits.erase(hits.begin());
        }
        int total = 0;
        for (const auto& [_, current]: hits) {
            total += current;
        }
        return total;
    }

private:
    map<int, int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
