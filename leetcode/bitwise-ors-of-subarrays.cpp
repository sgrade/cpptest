// 898. Bitwise ORs of Subarrays
// https://leetcode.com/problems/bitwise-ors-of-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Frontier Set
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, cur;
        for (int num : arr) {
            unordered_set<int> cur2 = {num};
            for (int x : cur)
                cur2.insert(num | x);
            cur = move(cur2);
            ans.insert(cur.begin(), cur.end());
        }
        return ans.size();
    }
};
