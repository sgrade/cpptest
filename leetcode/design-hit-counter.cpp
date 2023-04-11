// 362. Design Hit Counter
// https://leetcode.com/problems/design-hit-counter/

#include <bits/stdc++.h>

using namespace std;


class HitCounter {
public:
    void hit(int timestamp) {
        ++hits[timestamp];
    }
    
    int getHits(int timestamp) {
        map<int, int>::iterator it = hits.lower_bound(timestamp - 299);
        int total = 0;
        while (it != hits.end()) {
            total += it->second;
            ++it;
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
