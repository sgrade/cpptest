// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
// https://www.youtube.com/watch?v=ZI2z5pq0TqA

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        
        int n = height.size();
        int max_l = 0, max_r = 0;
        int idx_l = -1, idx_r = n;
        int current;
        
        for (int i = 0; i < n; ++i) {
            
            if (max_l <= max_r) {
                ++idx_l;
                current = max(0, min(max_l, max_r) - height[idx_l]);
                ans += current;
                max_l = max(max_l, height[idx_l]);
            }
            else {
                --idx_r;
                current = max(0, min(max_l, max_r) - height[idx_r]);
                ans += current;               
                max_r = max(max_r, height[idx_r]);
            }
        }
        
        return ans;
    }
};


int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    Solution sol;
    int ans = sol.trap(height);

    cout << ans << '\n';

    return 0;
}
