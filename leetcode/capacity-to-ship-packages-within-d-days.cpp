// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Capacity To Ship Packages Within D Days
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0, mid;
        for (const int& w: weights) {
            right += w;
            left = max(left, w);
        }
        while (left < right) {
            mid = left + (right - left) / 2;
            if (CanShip(weights, days, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
private:
    bool CanShip (vector<int>& weights, int days, const int& capacity) {
        int load = 0;
        for (const int& w: weights) {
            load += w;
            if (load > capacity) {
                --days;
                load = w;
            }
        }
        return days > 0;
    }
};
