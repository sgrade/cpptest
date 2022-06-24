// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map <char, int> count_t;
        for (int i = 0; i < t.size(); ++i) 
            ++count_t[t[i]];
        
        vector<pair<int, char>> filtered_s;
        for (int i = 0; i < s.size(); ++i) {
            if (count_t.find(s[i]) != count_t.end()) {
                filtered_s.push_back(pair<int, char>(i, s[i]));
            }
        }
        
        int need = count_t.size(), have = 0;
        int left = 0, right = 0;
        char ch;
        unordered_map<char, int> count_window;
        pair<int, int> ans(numeric_limits<int>::max(), 0);
        int d;
        
        while (right < filtered_s.size()) {
            ch = filtered_s[right].second;
            count_window[ch]++;
            if (count_window[ch] == count_t[ch]) {
                ++have;
            }
            
            while (have >= need && left <= right) {
                ch = filtered_s[left].second;
                d = filtered_s[right].first - filtered_s[left].first + 1;
                if (d < ans.first) {
                    ans.first = d;
                    ans.second = filtered_s[left].first;
                }
                --count_window[ch];
                if (count_window[ch] < count_t[ch]) 
                    --have;
                ++left;
            }
            
            ++right;
        }
        
        if (ans.first != numeric_limits<int>::max()) {
            return s.substr(ans.second, ans.first);
        }
            
        return "";
    }
};


int main() {

    return 0;
}
