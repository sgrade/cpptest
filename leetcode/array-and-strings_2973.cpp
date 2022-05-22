// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2973/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        vector<string> words;
        
        map<string, int> cnt;
        
        int n = paragraph.size();
        int i = 0;
        while (i < n) {
            string s = "";
            int j = i;
            while (j < n) {
                if (isalpha(paragraph[j])) {
                    s += tolower(paragraph[j]);
                }
                else {
                    break;
                }
                ++j;
            }
            if (!s.empty()) {
                ++cnt[s];
            }
            i = j + 1;
        }
        
        string ans;
        int max_cnt = 0;
        for (auto &p: cnt) {
            if (p.second > max_cnt) {
                if (find(banned.begin(), banned.end(), p.first) != banned.end()) continue;
                ans = p.first;
                max_cnt = p.second;
            }
        }
        
        return ans;
    }
};

int main() {

    // Input:
    // string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    // vector<string> banned = {"hit"};

    string paragraph = "a, a, a, a, b,b,b,c, c";
    vector<string> banned = {"a"};

    Solution sol;
    string ans = sol.mostCommonWord(paragraph, banned);
    
    cout << ans << endl;
    
    return 0;
}
