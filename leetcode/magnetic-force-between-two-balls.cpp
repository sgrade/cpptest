// 1552. Magnetic Force Between Two Balls
// https://leetcode.com/problems/magnetic-force-between-two-balls/

#include <bits/stdc++.h>

using namespace std;


// Key idea is from the Editorial's solution
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = position.size();
        sort (position.begin(), position.end());
        --m;
        int mx = (position[n - 1] + m - 1) / m;
        int ans = 1;
        int left = 1, right = mx, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            bool placed = canPlace (mid, position, m);
            if (placed) {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;

        }
        return ans;
    }

private:
    int n;
    bool canPlace (int force, const vector<int>& position, int m) {
        int i = 0, current_force;
        for (int j = 1; j < n; ++j) {
            current_force = position[j] - position[i];
            if (current_force >= force) {
                i = j;
                --m;
                if (m == 0)
                    return true;
            }
        }
        return false;
    }
};
