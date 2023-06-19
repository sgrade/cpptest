// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, ans = 0;
        for (const int& g: gain) {
            alt += g;
            ans = max(ans, alt);
        }
        return ans;
    }
};
