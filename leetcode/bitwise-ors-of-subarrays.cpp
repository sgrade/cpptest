// 898. Bitwise ORs of Subarrays
// https://leetcode.com/problems/bitwise-ors-of-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Frontier Set
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans, cur;
        cur.emplace(0);
        for (const int num: arr) {
            set<int> cur2;
            for (const int cur_num: cur)
                cur2.emplace(num | cur_num);
            cur2.emplace(num);
            cur = cur2;
            ans.insert(cur.begin(), cur.end());
        }
        return ans.size();
    }
};
