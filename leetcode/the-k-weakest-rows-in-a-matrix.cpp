// 1337. The K Weakest Rows in a Matrix
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> weakest(n);
        for (int i = 0; i < n; ++i) {
            int soldiers = distance (mat[i].begin(), find(mat[i].begin(), mat[i].end(), 0));
            weakest[i] = {soldiers, i};
        }
        sort(weakest.begin(), weakest.end());
        vector<int> ans(k);
        for (int j = 0; j < k; ++j)
            ans[j] = weakest[j].second;
        return ans;
    }
};
