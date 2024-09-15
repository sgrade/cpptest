// 1257. Smallest Common Region
// https://leetcode.com/problems/smallest-common-region/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Lowest Common Ancestor of a Generic Tree
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (const vector<string>& region: regions) {
            string parent = region[0];
            for (int i = 1; i < region.size(); ++i)
                parents[region[i]] = parent;
        }
        vector<string> path1 = GetPath(region1);
        vector<string> path2 = GetPath(region2);
        int i1 = 0, i2 = 0;
        string ans;
        while (i1 < path1.size() && i2 < path2.size() && path1[i1] == path2[i2]) {
            ans = path1[i1];
            ++i1;
            ++i2;
        }
        return ans;
    }

private:
    unordered_map<string, string> parents;
    vector<string> GetPath (string node) {
        vector<string> path;
        path.emplace_back(node);
        while (parents.find(node) != parents.end()) {
            string parent = parents[node];
            path.emplace_back(parent);
            node = parent;
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
