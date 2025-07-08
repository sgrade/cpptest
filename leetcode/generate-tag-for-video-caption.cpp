// 3582. Generate Tag for Video Caption
// https://leetcode.com/problems/generate-tag-for-video-caption/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string generateTag(string caption) {
        istringstream iss(caption);
        string ans = "#";
        
        string tmp;       
        while (getline(iss, tmp, ' ')) {
            tmp[0] = toupper(tmp[0]);
            for (int i = 1; i < tmp.size(); ++i)
                tmp[i] = tolower(tmp[i]);
            ans += tmp;
            if (ans.size() > 100) {
                ans.erase(100);
                break;
            }
        }
        ans[1] = tolower(ans[1]);

        return ans;
    }
};
