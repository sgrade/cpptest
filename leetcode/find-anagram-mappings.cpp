// 760. Find Anagram Mappings
// https://leetcode.com/problems/find-anagram-mappings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int, int> ar2;
        for (int i = 0; i < nums2.size(); ++i)
            ar2[nums2[i]] = i;
        vector<int> ans;
        for (const int& num: nums1)
            ans.emplace_back(ar2[num]);
        return ans;
    }
};
