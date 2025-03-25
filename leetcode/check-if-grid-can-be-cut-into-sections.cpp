// 3394. Check if Grid can be Cut into Sections
// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Line Sweep
class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            return check(rectangles, 0) || check(rectangles, 1);
        }

    private:
        bool check(vector<vector<int>>& rectangles, int z) {
            int gaps = 0;
            sort (rectangles.begin(), rectangles.end(), [z](const vector<int>& v1, const vector<int>& v2) {
                return v1[z] < v2[z];
            });
            int cur = rectangles[0][z + 2];
            for (int i = 1; i < rectangles.size(); ++i) {
                vector<int>& r = rectangles[i];
                if (cur <= r[z])
                    ++gaps;
                cur = max(cur, r[z + 2]);
            }
            return gaps >= 2;
        }
    };
