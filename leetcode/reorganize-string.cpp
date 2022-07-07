// 767. Reorganize String
// https://leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
    
        unordered_map<char, int> counter;
        for (const auto &c: s) {
            ++counter[c];
        }

        int mx = 0;
        for (const auto &[key, value]: counter) {
            mx = max(mx, value);
        }

        // + 2 - 1 is to ceil it
        if (mx > (s.size() + 2 - 1) / 2) {
            return "";
        }

        vector<pair<char, int>> v;
        for (const auto &[key, value]: counter) {
            v.emplace_back(pair<char, int>(key, value));
        }
        // n(long(n))
        sort(v.begin(), v.end(), [](pair<char, int> x, pair<char, int> y){
            return x.second > y.second;
        });
        // {{'a',3},{'b',2},{'c',1}} 
        // {{'a',2},{'b',2},{'c',1},{'d',1}} 

        vector<char> pre_output(n);
        int index_v = 0;
        for (int i = 0; i < n; i += 2) {
            if (v[index_v].second > 0) {
                pre_output[i] = v[index_v].first;
                // a, _, a, _, a, _
                // a, _, a, _, b, _
                --v[index_v].second;
            }
            else {
                ++index_v;
                i -= 2;
            }
        }

        for (int i = 1; i < n; i += 2) {
            if (v[index_v].second > 0) {
                pre_output[i] = v[index_v].first;
                // a, _, a, _, a, _
                // a, _, a, _, b, _
                --v[index_v].second;
            }
            else {
                ++index_v;
                i -= 2;
            }
        }

        for (int i = 0; i < pre_output.size(); ++i) {
            s[i] = pre_output[i];
        }
        return s;
    }
};
