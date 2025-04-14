// 1534. Count Good Triplets
// https://leetcode.com/problems/count-good-triplets/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Enumeration
class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int ans = 0, n = arr.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        ++ans;
                    }
                }
            }
            return ans;
        }
    };
