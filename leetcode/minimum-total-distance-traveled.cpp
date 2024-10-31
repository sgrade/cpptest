// 2463. Minimum Total Distance Traveled
// https://leetcode.com/problems/minimum-total-distance-traveled/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Memoization
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        for (const auto& f: factory) {
            for (int i = 0; i < f[1]; ++i)
                factory_positions.emplace_back(f[0]);
        }

        robots = robot.size(), factories = factory_positions.size();
        memo.resize(robots, vector<long long>(factories, -1));

        long long ans = GetMinDistance (0, 0, robot);
        return ans;
    }

private:
    int robots, factories;
    vector<int> factory_positions;
    vector<vector<long long>> memo;
    long long GetMinDistance (int robot_idx, int factory_idx, vector<int>& robot) {
        if (robot_idx == robots)
            return 0;
        if (factory_idx == factories)
            return 1e12;
        if (memo[robot_idx][factory_idx] != -1)
            return memo[robot_idx][factory_idx];
        long long assign = abs(robot[robot_idx] - factory_positions[factory_idx]) + GetMinDistance (robot_idx + 1, factory_idx + 1, robot);
        long long skip = GetMinDistance (robot_idx, factory_idx + 1, robot);
        return memo[robot_idx][factory_idx] = min(assign, skip);
    }
};
