// 1310. XOR Queries of a Subarray
// https://leetcode.com/problems/xor-queries-of-a-subarray/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Prefix XOR Array
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] ^ arr[i];

        vector<int> ans;
        for (const vector<int>& query: queries){
            int left = query[0], right = query[1];
            int current_ans = prefix[right + 1] ^ prefix[left];
            ans.emplace_back(current_ans);
        }
        return ans;
    }
};
