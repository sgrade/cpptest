// 1539. Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/

#include <bits/stdc++.h>

using namespace std;


// Optimized my solution using Leetcode's Approach 2: Binary Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left + k;        
    }
};
