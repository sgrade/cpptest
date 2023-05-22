// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int, int> counter;
        for (const int& el: nums)
            ++counter[el];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto& [el, cnt]: counter) {
            pq.emplace(cnt, el);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans(k);
        while (k--) {
            ans[k] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
