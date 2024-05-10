// 786. K-th Smallest Prime Fraction
// https://leetcode.com/problems/k-th-smallest-prime-fraction/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Priority Queue
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<
            pair<double, pair<int, int>>,
            vector<pair<double, pair<int, int>>>,
            greater<pair<double, pair<int, int>>>> pq;

        for (int i = 0; i < arr.size(); ++i)
            pq.emplace(1.0 * arr[i] / arr.back(), pair<int, int>(i, arr.size() - 1));

        while (--k) {
            auto [i, j] = pq.top().second;
            pq.pop();
            --j;
            pq.emplace(1.0 * arr[i] / arr[j], pair<int, int>(i, j));
        }

        auto [i, j] = pq.top().second;
        return {arr[i], arr[j]};
    }
};
