// 670. Maximum Swap
// https://leetcode.com/problems/maximum-swap/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (num < 10)
            return num;
        string orig = to_string(num);
        string sorted = orig;
        sort(sorted.begin(), sorted.end(), greater<>());
        int i = 0;
        for (int j = 0; j < orig.size(); ++j) {
            if (orig[j] != sorted[j]) {
                int left = orig[j];
                int right = sorted[j];
                size_t idx_left = orig.find(left);
                size_t idx_right = orig.find_last_of(right);
                swap(orig[idx_left], orig[idx_right]);
                break;
            }
        }
        return stoi(orig);
    }
};
