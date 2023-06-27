// 373. Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <bits/stdc++.h>

using namespace std;


// Memory Limit Exceeded
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                ans.emplace_back(vector<int>{nums1[i], nums2[j]});
            }
        }
        sort(ans.begin(), ans.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] + v1[1] < v2[0] + v2[1];
        });
        ans.erase(ans.begin() + min(k, (int)ans.size()), ans.end());
        return ans;
    }
};
