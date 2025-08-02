// 2561. Rearranging Fruits
// https://leetcode.com/problems/rearranging-fruits/

#include <bits/stdc++.h>

using namespace std;


// // Based on Editorial's Approach: Greedy
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int mn = std::min(
            *std::min_element(basket1.begin(), basket1.end()),
            *std::min_element(basket2.begin(), basket2.end())
        );
        unordered_map<int, int> counter;
        for (int b1 : basket1) ++counter[b1];
        for (int b2 : basket2) --counter[b2];

        vector<int> basket;
        for (const auto& [num, cnt]: counter) {
            if (cnt % 2 != 0)
                return -1;
            for (int i = 0; i < abs(cnt) / 2; ++i)
                basket.emplace_back(num);
        }

        int pos = basket.size() / 2;
        nth_element(basket.begin(), basket.begin() + pos, basket.end());
        long long ans = accumulate(basket.begin(), basket.begin() + pos, 0LL, 
            [&](long long res, int x){
                return res + min(2 * mn, x);
        });
        return ans;
    }
};
