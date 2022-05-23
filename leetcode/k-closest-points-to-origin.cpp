// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2){
            return (p1[0]*p1[0] + p1[1]*p1[1]) < (p2[0]*p2[0] + p2[1]*p2[1]);
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
