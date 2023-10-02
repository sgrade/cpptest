// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool winnerOfGame(string colors) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        size_t n = colors.size();
        int a = 0, b = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
                ++a;
            else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
                ++b;
        }
        if (a > b)
            return true;
        return false;
    }
};
