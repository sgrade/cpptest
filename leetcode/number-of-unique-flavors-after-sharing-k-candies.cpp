// 2107. Number of Unique Flavors After Sharing K Candies
// https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from Editorial's Approach 1: Sliding Window
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> counter;
        for (const int& candy: candies)
            ++counter[candy];
        int uniq_left = counter.size();
        if (k == 0)
            return uniq_left;

        int uniq_given = 0;
        for (int i = 0; i < k; ++i){
            if (--counter[candies[i]] == 0)
                ++uniq_given;
        }
        uniq_left = counter.size() - uniq_given;

        int left = 0, right = k, ans = uniq_left;
        while (right < candies.size()) {
            if (++counter[candies[left]] == 1)
                --uniq_given;
            if (--counter[candies[right]] == 0)
                ++uniq_given;
            uniq_left = counter.size() - uniq_given;
            ans = max(ans, uniq_left);
            ++left;
            ++right;
        }
        return ans;
    }
};
