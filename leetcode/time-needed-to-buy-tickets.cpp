// 2073. Time Needed to Buy Tickets
// https://leetcode.com/problems/time-needed-to-buy-tickets/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int x = tickets[k];
        int ans = x;
        for (int i = 0; i < k; ++i)
            ans += min(tickets[i], x);
        --x;
        for (int i = k + 1; i < tickets.size(); ++i)
            ans += min(tickets[i], x);
        return ans;
    }
};
