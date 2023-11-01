// 492. Construct the Rectangle
// https://leetcode.com/problems/construct-the-rectangle/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> constructRectangle(int area) {
        int x = sqrt(area);
        vector<int> ans(2, 0);
        for (int i = x; i <= area; ++i) {
            if (area % i == 0) {
                ans[0] = i;
                ans[1] = area / i;
                sort(ans.begin(), ans.end(), greater<int>());
                break;
            }
        }
        return ans;
    }
};
