// 3189. Minimum Moves to Get a Peaceful Board
// https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = rooks.size(), ans = 0;
        sort(rooks.begin(), rooks.end());
        for (int i = 0; i < n; ++i)
            ans += abs(i - rooks[i][0]);
        sort(rooks.begin(), rooks.end(), [&](const vector<int>& rook1, const vector<int>& rook2){
            return rook1[1] < rook2[1];
        });
        for (int i = 0; i < n; ++i)
            ans += abs(i - rooks[i][1]);
        return ans;
    }
};
