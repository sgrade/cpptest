// 2558. Take Gifts From the Richest Pile
// https://leetcode.com/problems/take-gifts-from-the-richest-pile/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k--) {
            int mx = pq.top();
            pq.pop();
            pq.emplace(sqrt(mx));
        }
        long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
