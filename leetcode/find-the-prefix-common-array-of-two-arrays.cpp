// 2657. Find the Prefix Common Array of Two Arrays
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> counter(51);
        int current_ans = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int a = A[i], b = B[i];
            ++counter[a], ++counter[b];
            if (counter[a] == 2)
                ++current_ans;
            if (counter[b] == 2 && a != b)
                ++current_ans;
            ans[i] = current_ans;
        }
        return ans;
    }
};
