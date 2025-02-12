// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size(), ans = -1;
        unordered_map<int, multiset<int>> counter;
        for (const int& num: nums) {
            int x = num, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            counter[sum].emplace(num);
        }

        for (const auto& [_, st]: counter) {
            if (st.size() > 1) {
                multiset<int>::reverse_iterator rit = st.rbegin();
                int current_ans = *rit;
                ++rit;
                current_ans += *rit;
                ans = max(ans, current_ans);
            }
        }
        return ans;
    }
};
