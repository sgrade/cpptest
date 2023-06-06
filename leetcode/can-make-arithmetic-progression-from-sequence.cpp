// 1502. Can Make Arithmetic Progression From Sequence
// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        bool ans = true;
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != d) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
