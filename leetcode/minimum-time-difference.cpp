// 539. Minimum Time Difference
// https://leetcode.com/problems/minimum-time-difference/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(timePoints.begin(), timePoints.end());

        // from the last time point around the clock to the first time point
        chrono::system_clock::time_point t_last = ParseTime(timePoints[timePoints.size() - 1]);
        chrono::system_clock::time_point t_first = ParseTime(timePoints[0]);
        auto ans = std::chrono::duration_cast<std::chrono::minutes>(t_last - t_first).count();
        ans = min(ans, 1440 - ans);

        for (int i = 1; i < timePoints.size(); ++i) {
            chrono::system_clock::time_point t1 = ParseTime(timePoints[i]);
            chrono::system_clock::time_point t0 = ParseTime(timePoints[i - 1]);
            auto d = std::chrono::duration_cast<std::chrono::minutes>(t1 - t0).count();
            ans = min(ans, d);
        }
        return ans;
    }

private:
    const string format = "%H:%M";
    chrono::system_clock::time_point ParseTime(const string& t) {
        tm tmStruct = {};
        istringstream ss(t);
        ss >> get_time(&tmStruct, format.c_str());
        return chrono::system_clock::from_time_t(mktime(&tmStruct));
    }
};
