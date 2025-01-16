// 2425. Bitwise XOR of All Pairings
// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Hash Map
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, long> counter;
        for (const int& num: nums1)
            counter[num] += n2;
        for (const int& num: nums2)
            counter[num] += n1;
        int ans = 0;
        for (const auto& [num, cnt]: counter){
            if (cnt % 2 == 1)
                ans ^= num;
        }
        return ans;
    }
};
