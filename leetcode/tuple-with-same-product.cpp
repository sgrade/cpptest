// 1726. Tuple with Same Product
// https://leetcode.com/problems/tuple-with-same-product/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Product Frequency Hash Map
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size(), ans = 0;
        unordered_map<int, int> counter;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j)
                ++counter[nums[i] * nums[j]];
        }

        for (const auto& [_, count]: counter) {
            int pairs = (count - 1) * count / 2;
            ans += 8 * pairs;
        }
        return ans;
    }
};
