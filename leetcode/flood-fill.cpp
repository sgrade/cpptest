// 733. Flood Fill
// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldColor_ = image[sr][sc];
        newColor_ = newColor;
        m = image.size();
        n = image[sr].size();
        if (oldColor_ != newColor_) dfs(image, sr, sc);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c) {
        if (image[r][c] != oldColor_) return;
        
        image[r][c] = newColor_;
        
        if (r - 1 >= 0) dfs(image, r - 1, c);
        if (r + 1 < m) dfs(image, r + 1, c);
        if (c - 1 >= 0) dfs(image, r, c - 1);
        if (c + 1 < n) dfs(image, r, c + 1);
        
        return;
    }

private:
    int m, n;
    int oldColor_;
    int newColor_;
};
