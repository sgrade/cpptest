// 824. Goat Latin
// https://leetcode.com/problems/goat-latin/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string toGoatLatin(string sentence) {
        
      unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

      size_t left = 0;
      size_t right = -1;
      string tmp;
      size_t len;

      vector<string> words;
      while (true) {
        // Optimize copying first char here
        right = sentence.find(' ', left);
        tmp = sentence.substr(left, right - left);
        words.push_back(tmp);
        if (right == string::npos) break;
        left = right + 1;
      }

      vector<string> pre_ans;
      int i = 0;
      char c;
      for (; i < words.size(); ++i) {
        c = tolower(words[i][0]);
        if (words[i].size() == 1) {
          tmp = words[i];
        }
        else if (vowels.find(c) == vowels.end()) { 
          tmp = words[i].substr(1, words[i].size() - 1) + words[i][0];
        }
        else {
          tmp = words[i];
        }
        tmp += "ma";
        for (int j = 0; j < i + 1; ++j) {
          tmp += 'a';
        }
        pre_ans.emplace_back(tmp);
      }

      string ans;
      for (const string &s: pre_ans) {
        ans += s + ' ';
      }
      ans.pop_back();
      return ans;
    }
};
