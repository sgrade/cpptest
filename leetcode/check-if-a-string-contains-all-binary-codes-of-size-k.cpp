// 1461. Check If a String Contains All Binary Codes of Size K
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

#include <string>
#include <unordered_set>

using namespace std;

// Based on Editorial's Approach 1: Set
class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    int num_codes = 1 << k;
    unordered_set<string> seen;
    for (size_t i = k; i < s.size(); ++i) {
      string candidate = s.substr(i - k, k);
      if (!seen.count(candidate)) {
        seen.emplace(candidate);
        --num_codes;
        if (num_codes == 0) {
          return true;
        }
      }
    }
    return false;
  }
};