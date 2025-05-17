// 444. Sequence Reconstruction
// https://leetcode.com/problems/sequence-reconstruction/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/sequence-reconstruction/solutions/92600/c-one-pass-solution-with-explanation-and-comments
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indegree(n + 1);
        vector<set<int>> children_of(n + 1);
        for (const vector<int>& seq: sequences) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] < 1 || seq[i] > n)
                    return false;
                if (i > 0) {
                    int cur = seq[i], prev = seq[i - 1];
                    bool cur_is_not_child_of_prev = children_of[prev].find(cur) == children_of[prev].end();
                    if (cur_is_not_child_of_prev) {
                        children_of[prev].emplace(cur);
                        ++indegree[cur];
                    }
                }
            }
        }

        int cur = nums[0], neighbors = 1;
        if (indegree[cur] != 0)
            return false;
        while (neighbors == 1) {
            neighbors = 0;
            set<int>& cur_children = children_of[cur];
            for (const int& child: cur_children) {
                --indegree[child];
                if (indegree[child] == 0) {
                    ++neighbors;
                    cur = child;
                }
            }
            --n;
        }
        return n == 0;
    }
};
