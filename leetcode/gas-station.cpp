// 134. Gas Station
// https://leetcode.com/problems/gas-station/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int total = 0, current = 0, tmp;
        for (int i = 0; i < gas.size(); ++i) {
            tmp = gas[i] - cost[i];
            total += tmp;
            current += tmp;
            if (current < 0) {
                current = 0;
                ans = i + 1;
            }
        }
        return total >= 0 ? ans : -1;
    }
};
