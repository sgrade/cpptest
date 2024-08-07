// 273. Integer to English Words
// https://leetcode.com/problems/integer-to-english-words/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Pair-Based Approach
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        for (const auto& [x, s]: pairs) {
            if (num < x)
                continue;
            string prefix = num >= 100 ? numberToWords (num / x) + " " : "";
            string unit = s;
            string suffix = num % x == 0 ? "" : " " + numberToWords (num % x);
            return prefix + unit + suffix;
        }
        return "";
    }
private:
    vector<pair<int, string>> pairs = {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},
        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},
        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"}
    };
};
