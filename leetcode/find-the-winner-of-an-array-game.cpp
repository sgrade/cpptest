// 1535. Find the Winner of an Array Game
// https://leetcode.com/problems/find-the-winner-of-an-array-game/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cnt = 0;
        int idx = 1, n = arr.size();
        for (; cnt < k, idx < n; ++cnt) {
            if (arr[0] < arr[idx]) {
                swap(arr[0], arr[idx]);
                cnt = 1;
            }
            ++idx;
            if (cnt == k)
                break;
        }
        return arr[0];
    }
};
