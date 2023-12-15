// 1436. Destination City
// https://leetcode.com/problems/destination-city/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> froms;
        for (const vector<string>& path: paths)
            froms.emplace(path[0]);
        for (const vector<string>& path: paths)
            if (froms.find(path[1]) == froms.end())
                return path[1];
        return "";
    }
};
