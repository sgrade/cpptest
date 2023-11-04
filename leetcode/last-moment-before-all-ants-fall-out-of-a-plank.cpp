// 1503. Last Moment Before All Ants Fall Out of a Plank
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Ants Pass Each Other!
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (const int& num: left)
            ans = max(ans, num);
        for (const int& num: right)
            ans = max(ans, n - num);
        return ans;
    }
};
