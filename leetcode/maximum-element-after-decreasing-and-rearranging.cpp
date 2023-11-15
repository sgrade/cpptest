// 1846. Maximum Element After Decreasing and Rearranging
// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1] || arr[i] > d)
                ++d;
        }
        return d;
    }
};
