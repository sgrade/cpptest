// 256. Paint House
// https://leetcode.com/problems/paint-house/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 5: Dynamic Programming with Optimized Space Complexity
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        vector<int> previous_row = costs[n - 1], current_row(3);
        for (int i = n - 2; i >= 0; --i) {
            current_row = costs[i];
            current_row[0] += min(previous_row[1], previous_row[2]);
            current_row[1] += min(previous_row[0], previous_row[2]);
            current_row[2] += min(previous_row[0], previous_row[1]);
            previous_row = current_row;
        }
        return *min_element(previous_row.begin(), previous_row.end());
    }
};
