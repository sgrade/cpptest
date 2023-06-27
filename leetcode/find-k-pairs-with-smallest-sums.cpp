// 373. Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        auto comp = [](pair<int, vector<int>>& p1, pair<int, vector<int>>& p2) {
            return p1.first < p2.first;
        };
        priority_queue< pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(comp) > pq(comp);
        
        int cur_sum;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                cur_sum = nums1[i] + nums2[j];
                if (pq.size() == k) {
                    if (cur_sum > pq.top().first)
                        continue;
                    pq.pop();
                }
                pq.emplace(cur_sum, vector<int>{nums1[i], nums2[j]});
            }
        }

        vector<vector<int>> ans(pq.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
