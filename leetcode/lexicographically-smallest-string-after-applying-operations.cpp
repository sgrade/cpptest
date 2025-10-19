// 1625. Lexicographically Smallest String After Applying Operations
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

#include <string>
#include <numeric>
#include <algorithm>

using std::string;
using std::gcd;


// Explicit try-all implementation
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;

        // Concatenate to allow easy rotation substrings
        string ss = s + s;
        int g = gcd(b, n);

        for (int start = 0; start < n; start += g) {
            string base = ss.substr(start, n);

            // Try 0..9 additions for odd positions
            for (int addOdd = 0; addOdd < 10; ++addOdd) {
                string cur_ans_even = base;
                applyAddToParity(cur_ans_even, a, addOdd, 1);

                if (b % 2 == 1) {
                    // If b is odd, even positions can be changed independently -> try 0..9
                    for (int addEven = 0; addEven < 10; ++addEven) {
                        string cur_ans_odd = cur_ans_even;
                        applyAddToParity(cur_ans_odd, a, addEven, 0);
                        ans = min(ans, cur_ans_odd);
                    }
                } else {
                    // b even: parity of indices doesn't change by rotation, only odd additions matter
                    ans = min(ans, cur_ans_even );
                }
            }
        }

        return ans;
    }

private:
    // Apply (count * a) modulo 10 to all positions with given parity (0 or 1)
    void applyAddToParity(string &t, int a, int count, int parity) {
        int n = t.size();
        int delta = (count * a) % 10;
        for (int i = parity; i < n; i += 2) {
            int d = (t[i] - '0' + delta) % 10;
            t[i] = char('0' + d);
        }
    }
};
