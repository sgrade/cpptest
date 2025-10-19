// 1625. Lexicographically Smallest String After Applying Operations
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

#include <string>
#include <numeric>

using std::string;
using std::min;
using std::gcd;


// Based on Editorial's Lexicographically Smallest String After Applying Operations
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        this-> a = a, n = s.size();
        string ans = s;
        s = s + s;

        int g = gcd(b, n);
        for (int i = 0; i < n; i += g) {
            string t = s.substr(i, n);
            add(t, 1);
            if (b % 2) {
                add(t, 0);
            }
            ans = min(ans, t);
        }
        return ans;
    }

private:
    int a, n;
    void add (string& t, int start) {
        int mn = 10, times = 0;
        for (int i = 0; i < 10; ++i) {
            int added = ((t[start] - '0') + i * a) % 10;
            if (added < mn) {
                mn = added;
                times = i;
            }
        }
        for (int i = start; i < n; i += 2) {
            t[i] = '0' + ((t[i] - '0') + times * a) % 10;
        }
    }
};
