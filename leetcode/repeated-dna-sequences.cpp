// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>

using namespace std;


// VERY SLOW IMPLEMENTATION

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if (n < 10) {
            return ans;
        }
        deque<char> current;
        for (int i = 0; i < 10; ++i) {
            current.push_back(s[i]);
        }
        map<deque<char>, int> seen;
        ++seen[current];
        for (int i = 10; i < n; ++i) {
            current.pop_front();
            current.emplace_back(s[i]);
            if (seen.find(current) != seen.end() && seen[current] == 1) {
                ans.emplace_back(s.substr(i - 10 + 1, 10));
            }
            ++seen[current];
        }
        return ans;
    }
};
