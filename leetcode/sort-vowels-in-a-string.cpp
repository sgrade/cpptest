// 2785. Sort Vowels in a String
// https://leetcode.com/problems/sort-vowels-in-a-string/

#include <bits/stdc++.h>

using namespace std;


// Optimized with ideas from a sample 16ms solution.
class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> counter(128);
        for (int i = 0; i < n; ++i) {
            if (isVowel(s[i]))
                ++counter[s[i] - 'A'];
        }
        int counter_idx = 0;
        for (int i = 0; i <n; ++i) {
            if (isVowel(s[i])) {
                while (counter[counter_idx] == 0)
                    ++counter_idx;
                s[i] = counter_idx + 'A';
                --counter[counter_idx];
            }
        }
        return s;
    }
private:
    bool isVowel(char ch) {
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
    return false;
    }
};
