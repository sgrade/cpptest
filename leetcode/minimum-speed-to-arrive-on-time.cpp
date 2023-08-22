// 1870. Minimum Speed to Arrive on Time
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Binary Search
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        n = dist.size();
        int min_speed = -1, left = 1, right = 1e7, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (GetTime(dist, mid) > hour)
                left = mid + 1;
            else {
                min_speed = mid;
                right = mid - 1;
            }
        }
        return min_speed;
    }

private:
    int n;
    double GetTime (vector<int>& dist, int speed) {
        double total_time = 0.0;
        for (int i = 0; i < n; ++i) {
            double t = (double)dist[i] / (double)speed;
            total_time += i == n - 1 ? t : ceil(t);
        }
        return total_time;
    }
};
