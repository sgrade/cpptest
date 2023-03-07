// 2187. Minimum Time to Complete Trips
// https://leetcode.com/problems/minimum-time-to-complete-trips/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 0, right = 1LL * time[0] * totalTrips, mid, trips;
        while (left < right) {
            mid = left + (right - left) / 2;
            trips = CountTrips(time, mid);
            if (trips < totalTrips)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

private:
    long long CountTrips(vector<int>& time, const long long& candidate_time) {
        long long trips = 0;
        for (const int& t: time) 
            trips += candidate_time / t;
        return trips;
    }
};
