// 760. Find Anagram Mappings
// https://leetcode.com/problems/find-anagram-mappings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, queue<int>> ar2;
        for (int i = 0; i < n; ++i)
            ar2[nums2[i]].emplace(i);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = ar2[nums1[i]].front();
            ar2[nums1[i]].pop();
        }
        return ans;
    }
};
