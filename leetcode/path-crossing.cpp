// 1496. Path Crossing
// https://leetcode.com/problems/path-crossing/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPathCrossing(string path) {
        int row = 0, col = 0;
        // row: col
        unordered_map<int, unordered_set<int>> visited;
        visited[0].emplace(0);
        for (const char& ch: path) {
            row += directions[ch].first;
            col += directions[ch].second;
            if (visited[row].find(col) != visited[row].end())
                return true;
            visited[row].emplace(col);
        }
        return false;
    }
private:
    unordered_map<char, pair<int, int>> directions = {
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'E', {0, 1}},
        {'W', {0, -1}}
    };
};
