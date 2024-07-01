// 1550. Three Consecutive Odds
// https://leetcode.com/problems/three-consecutive-odds/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] % 2 == 1)
                ++odds;
            else
                odds = 0;
            if (odds == 3)
                return true;
        }
        return false;
    }
};
