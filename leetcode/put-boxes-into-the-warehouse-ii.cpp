// 1580. Put Boxes Into the Warehouse II
// https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/

#include <bits/stdc++.h>

using namespace std;


// Some hints are from the Editorial's Approach 1: Add Smallest Boxes to the Rightmost Warehouse Rooms from Both Ends
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int left = 0, right = warehouse.size() - 1, mn_left = warehouse[0], mn_right = warehouse[right];
        while (left < right) {
            if (warehouse[left] < mn_left)
                mn_left = warehouse[left];
            else
                warehouse[left] = mn_left;
            if (warehouse[right] < mn_right)
                mn_right = warehouse[right];
            else
                warehouse[right] = mn_right;
            if (mn_left < mn_right)
                --right;
            else
                ++left;
        }

        sort(boxes.begin(), boxes.end());
        sort(warehouse.begin(), warehouse.end());
        int ans = 0;
        int box_idx = 0;
        for (int i = 0; i < warehouse.size(); ++i) {
            if (box_idx == boxes.size())
                break;
            if (boxes[box_idx] <= warehouse[i]) {{
                ++ans;
                ++box_idx;
            }}
        }

        return ans;
    }
};
