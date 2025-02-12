// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, pair<int, int>> counter;
        for (const int& num: nums) {
            int x = num, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (num > counter[sum].first) {
                counter[sum].first = num;
                if (counter[sum].first > counter[sum].second)
                    swap(counter[sum].first, counter[sum].second);
            }
        }

        int ans = -1;
        for (auto& [_, p]: counter) {
            if (p.first > 0) {
                int current_ans = p.first + p.second;
                ans = max(ans, current_ans);
            }
        }
        return ans;
    }
};
