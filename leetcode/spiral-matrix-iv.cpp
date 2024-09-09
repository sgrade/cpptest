// 2326. Spiral Matrix IV
// https://leetcode.com/problems/spiral-matrix-iv/

#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = m, cols = n;
        ans.resize(m, vector<int>(n, -1));
        while (head) {
            val = head->val;
            head = head->next;
            ans[row][col] = val;
            CheckDirection();
        }
        return ans;
    }

private:
    int rows, cols, row = 0, col = 0, direction = 0, val;
    vector<vector<int>> ans;
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    void CheckDirection() {
        int r_diff = directions[direction].first;
        int c_diff = directions[direction].second;
        int new_row = row + r_diff;
        int new_col = col + c_diff;
        if (new_row < 0 || new_row == rows || new_col < 0 || new_col == cols || ans[new_row][new_col] != -1) {
            direction = (direction + 1) % 4;
            r_diff = directions[direction].first;
            c_diff = directions[direction].second;
        }
        row += r_diff;
        col += c_diff;
    }
};
