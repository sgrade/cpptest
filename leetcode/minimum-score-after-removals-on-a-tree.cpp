// 2322. Minimum Score After Removals on a Tree
// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Double DFS to Partition Connected Components
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        adj.resize(n);
        for (const vector<int>& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        for (const int num: nums)
            sum ^= num;

        dfs1(0, -1, nums);
        return ans;
    }

private:
    vector<vector<int>> adj;
    int sum = 0;
    int ans = numeric_limits<int>::max();

    int getScore(int part1, int part2, int part3) {
        int max_score = max({part1, part2, part3});
        int min_score = min({part1, part2, part3});
        return max_score - min_score;
    }

    int dfs1(int child, int parent, const vector<int>& nums) {
        int num = nums[child];
        for (int neighbor: adj[child]) {
            if (neighbor == parent)
                continue;
            num ^= dfs1(neighbor, child, nums);
        }

        for (int neighbor: adj[child]) {
            if (neighbor != parent)
                continue;
            dfs2(neighbor, child, num, child, nums);
        }

        return num;
    }

    int dfs2(int child, int parent, int oth, int anc, const vector<int>& nums) {
        int num = nums[child];
        for (int neighbor: adj[child]) {
            if (neighbor == parent)
                continue;
            num ^= dfs2(neighbor, child, oth, anc, nums);
        }
        if (parent == anc)
            return num;
        ans = min(ans, getScore(oth, num, sum ^ oth ^ num));
        return num;
    }
};
