// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/

#include <bits/stdc++.h>

using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version) {
    if (version == 3) return true;
    return false;
}


class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
