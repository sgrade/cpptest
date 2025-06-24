// 2200. Find All K-Distant Indices in an Array
// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> ans;
        int right = 0, search_start = 0, n = nums.size();
        while (right < n) {
            vector<int>::iterator it = find(nums.begin() + search_start, nums.end(), key);
            if (it == nums.end())
                break;
            int cur = distance(nums.begin(), it);
            int left = max(right, cur - k);
            right = min(cur + k, n - 1);
            for (int i = left; i <= right; ++i)
                ans.emplace_back(i);
            search_start = cur + 1;
            ++right;
        }
        return ans;
    }
};
