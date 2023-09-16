// 2833. Furthest Point From Origin
// https://leetcode.com/problems/furthest-point-from-origin/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, any = 0;
        for (const char& ch: moves) {
            if (ch == 'L') ++left;
            else if (ch == 'R') ++right;
            else ++any;
        }
        if (left > right)
            return left - right + any;
        else if (right > left)
            return right - left + any;
        return any;
    }
};
