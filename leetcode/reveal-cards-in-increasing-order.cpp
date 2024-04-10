// 950. Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < deck.size(); ++i)
            q.emplace(i);

        int idx_deck = 0;
        vector<int> ans(deck.size());
        while (!q.empty()) {
            int idx_q = q.front();
            ans[idx_q] = deck[idx_deck++];
            q.pop();
            if (!q.empty()) {
                q.emplace(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
