// 1167. Minimum Cost to Connect Sticks
// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap(sticks.begin(), sticks.end());
        int nxt;
        while (min_heap.size() > 1) {
            nxt = min_heap.top();
            min_heap.pop();
            nxt += min_heap.top();
            min_heap.pop();
            ans += nxt;
            min_heap.emplace(nxt);
        }
        return ans;
    }
};
