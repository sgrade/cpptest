// 358. Rearrange String k Distance Apart
// https://leetcode.com/problems/rearrange-string-k-distance-apart/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Based on Editorial's Approach 2: Greedy
class Solution {
 public:
  string rearrangeString(string s, int k) {
    unordered_map<char, int> counter;
    int max_count = 0;
    for (const char ch : s) {
      ++counter[ch];
      max_count = max(max_count, counter[ch]);
    }

    unordered_set<char> most_chars, second_chars;
    for (const auto& [ch, cnt] : counter) {
      if (cnt == max_count) {
        most_chars.emplace(ch);
      } else if (cnt == max_count - 1) {
        second_chars.emplace(ch);
      }
    }

    vector<string> segments(max_count);
    for (int i = 0; i < max_count; ++i) {
      for (char ch : most_chars) {
        segments[i] += ch;
      }
      if (i < max_count - 1) {
        for (char ch : second_chars) {
          segments[i] += ch;
        }
      }
    }

    int segment_id = 0;
    for (auto& [ch, cnt] : counter) {
      if (most_chars.count(ch) || second_chars.count(ch)) {
        continue;
      }
      while (cnt--) {
        segments[segment_id] += ch;
        segment_id = (segment_id + 1) % (max_count - 1);
      }
    }

    for (int i = 0; i < max_count - 1; ++i) {
      if ((int)segments[i].size() < k) {
        return "";
      }
    }

    string ans;
    for (string s : segments) {
      ans += s;
    }

    return ans;
  }
};
