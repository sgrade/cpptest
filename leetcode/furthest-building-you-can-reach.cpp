// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
        return dfs(0, heights, bricks, ladders);
    }
private:
    int n, ans = 0;
    int dfs(int i, vector<int>& heights, int bricks, int ladders) {
        if (i == n - 1)
            return i;
        int current_ans = i;
        int need_bricks = max(0, heights[i + 1] - heights[i]);
        if (need_bricks == 0)
            current_ans = max(current_ans, dfs(i + 1, heights, bricks, ladders));
        else {
            if (bricks >= need_bricks)
                current_ans = max(current_ans, dfs(i + 1, heights, bricks - need_bricks, ladders));
            if (ladders > 0)
                current_ans = max(current_ans, dfs(i + 1, heights, bricks, ladders - 1));
        }
        return current_ans;
    }
};
