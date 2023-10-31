// 2433. Find The Original Array of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Using XOR Properties, Space Optimized
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        for (int i = n - 1; i > 0; --i)
            pref[i] = pref[i] ^ pref[i - 1];
        return pref;
    }
};
