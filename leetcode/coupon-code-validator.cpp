// 3606. Coupon Code Validator
// https://leetcode.com/problems/coupon-code-validator/

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::string;
using std::vector;

class Solution {
 public:
  vector<string> validateCoupons(vector<string>& code,
                                 vector<string>& businessLine,
                                 vector<bool>& isActive) {
    for (size_t i = 0; i < code.size(); ++i) {
      if (!isActive[i]) continue;
      if (code[i].empty()) continue;
      string category = businessLine[i];
      if (find(categories.begin(), categories.end(), category) ==
          categories.end())
        continue;
      bool is_valid = true;
      for (const char& ch : code[i]) {
        if (isalnum(ch) || ch == '_')
          continue;
        else {
          is_valid = false;
          break;
        }
      }
      if (is_valid) coupons[category].emplace_back(code[i]);
    }

    vector<string> ans;
    for (auto& [category, coups] : coupons) {
      if (coups.empty()) continue;
      sort(coups.begin(), coups.end());
      ans.insert(ans.end(), coups.begin(), coups.end());
    }
    return ans;
  }

 private:
  map<string, vector<string>> coupons;
  set<string> categories = {"electronics", "grocery", "pharmacy", "restaurant"};
};
