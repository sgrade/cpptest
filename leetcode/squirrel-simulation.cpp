// 573. Squirrel Simulation
// https://leetcode.com/problems/squirrel-simulation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Simple Solution
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int ans = 0, d = INT_MIN;
        for (vector<int>& nut: nuts) {
            ans += (distance(nut, tree) * 2);
            d = max(d, distance(nut, tree) - distance(nut, squirrel));
        }
        return ans - d;
    }
private:
    int distance(vector<int>& point1, vector<int>& point2) {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
    }
};
