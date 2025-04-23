// 302. Smallest Rectangle Enclosing Black Pixels
// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Binary Search
class Solution {
    public:
        int minArea(vector<vector<char>>& image, int x, int y) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            rows = image.size(), cols = image[0].size();
            int left = traverseColumns (image, 0, y, 0, rows, true);
            int right = traverseColumns (image, y + 1, cols, 0, rows, false);
            int top = traverseRows(image, 0, x, left, right, true);
            int bot = traverseRows(image, x + 1, rows, left, right, false);
            return (right - left) * (bot - top);
        }

    private:
        int rows, cols;

        int traverseColumns(vector<vector<char>>& image, int t, int b, int top, int bot, bool white_to_black) {
            while (t != b) {
                int row = top, mid = (t + b) / 2;
                while (row < bot && image[row][mid] == '0')
                    ++row;
                if (row < bot == white_to_black)
                    b = mid;
                else
                    t = mid + 1;
            }
            return t;
        }

        int traverseRows(vector<vector<char>>& image, int l, int r, int left, int right, bool white_to_black) {
            while (l != r) {
                int col = left, mid = (r + l) / 2;
                while (col < right && image[mid][col] == '0')
                    ++col;
                if (col < right == white_to_black)
                    r = mid;
                else
                    l = mid + 1;
            }
            return l;
        }
    };
