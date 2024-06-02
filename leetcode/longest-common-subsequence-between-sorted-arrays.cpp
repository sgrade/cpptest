// 1940. Longest Common Subsequence Between Sorted Arrays
// https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        n = arrays.size();
        for (int i = 0; i < arrays[0].size(); ++i) {
            int target = arrays[0][i];
            if (isExistInAllArrays (target, arrays))
                ans.emplace_back(target);
        }
        return ans;
    }

private:
    int n;
    vector<int> ans;

    bool isExistInAllArrays (int target, vector<vector<int>>& arrays) {
        for (int i = 1; i < n; ++i) {
            if (binarySearch(target, arrays[i]) == false)
                return false;
        }
        return true;
    }

    bool binarySearch (int target, vector<int>& array) {
        int left = 0, right = array.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] == target)
                return true;
            else if (target < array[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
