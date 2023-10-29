// 832. Flipping an Image
// https://leetcode.com/problems/flipping-an-image/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& row: image)
            reverse(row.begin(), row.end());
        for (int row = 0; row < image.size(); ++row) {
            for (int col = 0; col < image[0].size(); ++col) {
                image[row][col] = !image[row][col];
            }
        }
        return image;
    }
};
