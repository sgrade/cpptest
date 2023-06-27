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
        auto comp = [](vector<int>& v1, vector<int>& v2) {
            return v1[0] + v1[1] < v2[0] + v2[1];
        };
        priority_queue< vector <int>, vector<vector<int>>, decltype(comp) > pq(comp);
        
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (pq.size() == k) {
                    if (nums1[i] + nums2[j] > pq.top()[0] + pq.top()[1])
                        continue;
                    pq.pop();
                }
                pq.emplace(vector<int>{nums1[i], nums2[j]});
            }
        }

        vector<vector<int>> ans(pq.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;
    }
};
