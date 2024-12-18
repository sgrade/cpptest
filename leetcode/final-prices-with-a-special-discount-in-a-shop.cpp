// 1475. Final Prices With a Special Discount in a Shop
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        stack<int> st;
        for (int i = 0; i < prices.size(); ++i) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.emplace(i);
        }
        return prices;
    }
};
