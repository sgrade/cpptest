// 1122. Relative Sort Array
// https://leetcode.com/problems/relative-sort-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> counter;
        for (const int& num: arr1)
            ++counter[num];
        int idx1 = 0;
        for (const int& num: arr2) {
            if (counter.find(num) != counter.end()) {
                do
                    arr1[idx1++] = num;
                while (--counter[num]);
            }
        }
        for (auto& [num, cnt]: counter) {
            while (cnt--)
                arr1[idx1++] = num;
        }

        return arr1;
    }
};
