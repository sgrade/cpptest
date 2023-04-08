// 933. Number of Recent Calls
// https://leetcode.com/problems/number-of-recent-calls/

#include <bits/stdc++.h>

using namespace std;


class RecentCounter {
public:
    RecentCounter() {}
    int ping(int t) {
        q.emplace(t);
        while (q.front() < t - 3000)
            q.pop();
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
