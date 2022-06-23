// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> best_k;
        pair<int, int> cur;
        for (int i = 0; i < points.size(); ++i) {
            cur.first = getDistance(points[i]);
            cur.second = i;
            if (best_k.size() < k) {
                best_k.push(cur);
            }
            else if (cur.first < best_k.top().first) {
                best_k.pop();
                best_k.push(cur);
            }
        }

        vector<vector<int>> ans(k);
        int idx;
        for (int i = 0; i < k; ++i) {
            idx = best_k.top().second;
            ans[i] = points[idx];
            best_k.pop();
        }

        return ans;
    }

    int getDistance(const vector<int> &v) {
        return v[0] * v[0] + v[1] * v[1];
    }
};
