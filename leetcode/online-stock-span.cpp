// 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Monotonic Stack
class StockSpanner {
public:
    int next(int price) {
        int ans = 1;
        while (!st.empty() && st.top().first <= price) {
            ans += st.top().second;
            st.pop();
        }
        st.emplace(price, ans);
        return ans;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
