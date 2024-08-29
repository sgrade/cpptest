// 666. Path Sum IV
// https://leetcode.com/problems/path-sum-iv/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth First Search
class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty())
            return 0;

        for (const int& num: nums) {
            int coordinates = num / 10;
            int val = num % 10;
            nodes[coordinates] = val;
        }

        dfs (nums[0] / 10, 0);
        return ans;
    }

private:
    int ans = 0;
    // <coordinates, value>
    unordered_map<int, int> nodes;

    void dfs (int coordinates, int path_sum) {
        int depth = coordinates / 10;
        int position = coordinates % 10;
        int right = (depth + 1) * 10 + position * 2; 
        int left = right - 1;
        path_sum += nodes[coordinates];
        if (nodes.find(left) == nodes.end() && nodes.find(right) == nodes.end()) {
            ans += path_sum;
            return;
        }
        if (nodes.find(left) != nodes.end())
            dfs (left, path_sum);
        if (nodes.find(right) != nodes.end())
            dfs (right, path_sum);
    }
};
