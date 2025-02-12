// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, vector<int>> counter;
        for (const int& num: nums) {
            int x = num, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            counter[sum].emplace_back(num);
        }

        int ans = -1;
        for (auto& [_, v]: counter) {
            if (v.size() > 1) {
                sort(v.begin(), v.end());
                int current_ans = v[v.size() - 1] + v[v.size() - 2];
                ans = max(ans, current_ans);
            }
        }
        return ans;
    }
};
