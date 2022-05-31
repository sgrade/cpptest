// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ans = 0, curAns = 0;
        
        int n = height.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            
            curAns = min(height[left], height[right]) * (right - left);
            ans = max(ans, curAns);
            
            if (height[left] < height[right]) ++left;
            else --right;
        }
        
        return ans;
    }
};


int main() {

    vector<int> height = {2,3,4,5,18,17,6};

    Solution sol;

    cout << sol.maxArea(height) << '\n';

    return 0;
}
