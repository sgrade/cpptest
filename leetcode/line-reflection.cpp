// 356. Line Reflection
// https://leetcode.com/problems/line-reflection/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/line-reflection/solutions/3331741/solution/
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return true;

        int min_x = points[0][0];
        int max_x = min_x;

        set<pair<int, int>> st;
        for (const vector<int>& v: points) {
            min_x = min(v[0], min_x);
            max_x = max(v[0], max_x);
            st.emplace(pair<int, int>(v[0], v[1]));
        }

        int sm = min_x + max_x;

        int x2;
        for (auto& [x1, y]: st) {
            x2 = sm - x1;
            if (st.find({x2, y}) == st.end())
                return false;
        }

        return true;
    }
};
