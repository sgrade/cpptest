// 1481. Least Number of Unique Integers after K Removals
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int, int> counter;
        for (const int& num: arr)
            ++counter[num];
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& [_, cnt]: counter)
            pq.emplace(cnt);
        while (!pq.empty() && k >= pq.top()) {
            k -= pq.top();
            pq.pop();
        }
        return pq.size();
    }
};
