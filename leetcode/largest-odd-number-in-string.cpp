// 1903. Largest Odd Number in String
// https://leetcode.com/problems/largest-odd-number-in-string/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string largestOddNumber(string num) {
      int n = num.size();
      for (int i = num.size() - 1; i >= 0; --i) {
        if ((int)num[i] % 2 != 0) {
          return num.substr(0, i + 1);
        }
      }
      return "";
    }
};
