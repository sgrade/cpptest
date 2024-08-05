// 2053. Kth Distinct String in an Array
// https://leetcode.com/problems/kth-distinct-string-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_map<string, int> counter;
        for (const string& s: arr) 
            ++counter[s];
        for (const string& s: arr) {
            if (counter[s] == 1)
                --k;
            if (k == 0)
                return s;
        }
        return "";
    }
};
