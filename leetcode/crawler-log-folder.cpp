// 1598. Crawler Log Folder
// https://leetcode.com/problems/crawler-log-folder/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (const string& operation: logs) {
            if (operation == "./")
                continue;
            else if (operation == "../")
                ans = max(0, --ans);
            else
                ++ans;
        }
        return ans;
    }
};
