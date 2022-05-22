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
        int maxL = 0, maxR = 0;
        int idxL = -1, idxR = n;
        int current;
        
        for (int i = 0; i < n; ++i) {
            
            if (maxL <= maxR) {
                ++idxL;
                current = max(0, min(maxL, maxR) - height[idxL]);
                ans += current;
                maxL = max(maxL, height[idxL]);
            }
            else {
                --idxR;
                current = max(0, min(maxL, maxR) - height[idxR]);
                ans += current;               
                maxR = max(maxR, height[idxR]);
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
