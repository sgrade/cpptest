// 950. Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < n; ++i)
            q.emplace(i);

        vector<int> ans(deck.size());
        for (int i = 0; i < n; ++i) {
            ans[q.front()] = deck[i];
            q.pop();
            if (!q.empty()) {
                q.emplace(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
