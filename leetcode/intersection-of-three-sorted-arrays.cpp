// 1213. Intersection of Three Sorted Arrays
// https://leetcode.com/problems/intersection-of-three-sorted-arrays/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int idx1 = 0, n1 = arr1.size(), idx2 = 0, n2 = arr2.size(), idx3 = 0, n3 = arr3.size();
        int mn;
        vector<int> ans;
        while (idx1 < n1 && idx2 < n2 && idx3 < n3) {
            if (arr1[idx1] == arr2[idx2] && arr2[idx2] == arr3[idx3]) {
                ans.emplace_back(arr1[idx1]);
                ++idx1;
                ++idx2;
                ++idx3;
            }
            else {
                mn = min ({arr1[idx1], arr2[idx2], arr3[idx3]});
                if (mn == arr1[idx1])
                    ++idx1;
                else if (mn == arr2[idx2])
                    ++idx2;
                else
                    ++idx3;
            }
        }
        return ans;
    }
};
