// 944. Delete Columns to Make Sorted
// https://leetcode.com/problems/delete-columns-to-make-sorted/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        std::unordered_map<char, int> chars = {
            {'a', 0},{'b', 1},{'c', 2},{'d', 3},{'e', 4},{'f', 5},{'g', 6},{'h', 7}, {'i', 8},{'j', 9},
            {'k', 10},{'l', 11},{'m', 12},{'n', 13},{'o', 14},{'p', 15},{'q', 16},{'r', 17},{'s', 18},
            {'t', 19},{'u', 20},{'v', 21},{'w', 22},{'x', 23},{'y', 24},{'z', 25}
        };
        int prev, current;
        for (int column = 0; column < strs[0].size(); ++column) {
            prev = 0;
            for (int row = 0; row < strs.size(); ++row) {
                current = chars[strs[row][column]];
                if (current < prev) {
                    ++ans;
                    break;
                }
                prev = current;
            }
        }
        return ans;
    }
};
