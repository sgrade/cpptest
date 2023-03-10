// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (vowels.find(s[left]) == vowels.end()) 
                ++left;
            if (vowels.find(s[right]) == vowels.end())
                --right;
            if (left < right)
                swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};
