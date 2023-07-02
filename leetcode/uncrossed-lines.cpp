// 1035. Uncrossed Lines
// https://leetcode.com/problems/uncrossed-lines/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 1: Recursive Dynamic Programming
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> checked(n1 + 1, vector<int>(n2 + 1, -1));
        return check(n1, n2, nums1, nums2, checked);
    }

private:
    int check (int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& checked) {
        if (idx1 <= 0 || idx2 <= 0)
            return 0;
        if (checked[idx1][idx2] != -1)
            return checked[idx1][idx2];

        if (nums1[idx1 - 1] == nums2[idx2 - 1])
            checked[idx1][idx2] = 1 + check(idx1 - 1, idx2 - 1, nums1, nums2, checked);
        else {
            checked[idx1][idx2] = max(
                check(idx1, idx2 - 1, nums1, nums2, checked), 
                check(idx1 - 1, idx2, nums1, nums2, checked)
            );
        }
        return checked[idx1][idx2];
    }
};
