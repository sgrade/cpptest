// 1574. Shortest Subarray to be Removed to Make Array Sorted
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach: Two Pointers
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1])
            --right;
        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            while (right < arr.size() && arr[left] > arr[right])
                ++right;
            ans = min(ans, right - left - 1);
            ++left;
        }
        return ans;
    }
};
