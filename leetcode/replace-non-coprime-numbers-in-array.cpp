// 2197. Replace Non-Coprime Numbers in Array
// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

#include <vector>
#include <numeric>

using std::vector;
using std::gcd;
using std::lcm;


// Based on https://leetcode.com/problems/replace-non-coprime-numbers-in-array/solutions/7194480/beats-94-simple-explanation-beginner-friendly-efficient
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num : nums) {
            int replacement = num;
            while (!st.empty() && gcd(st.back(), replacement) > 1) {
                replacement = lcm(st.back(), replacement);
                st.pop_back();
            }
            st.emplace_back(replacement);
        }
        return st;
    }
};
