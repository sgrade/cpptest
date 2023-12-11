// 1287. Element Appearing More Than 25% In Sorted Array
// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (arr.size() < 4)
            return arr[0];
        double n = 1.0 * arr.size() / 4;
        int cnt = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == arr[i - 1]) {
                ++cnt;
                if (cnt > n)
                    return arr[i];
            }
            else
                cnt = 1;
        }
        return -1;
    }
};
