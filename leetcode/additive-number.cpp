// 306. Additive Number
// https://leetcode.com/problems/additive-number/

#include <bits/stdc++.h>

using namespace std;


// Some ideas are from https://leetcode.com/problems/additive-number/solutions/75576/0ms-concise-c-solution-perfectly-handles-the-follow-up-and-leading-0s
class Solution {
public:
    bool isAdditiveNumber(string num) {
        n = num.size();
        if (num.size() < 3) return false;
        for (size_t len1 = 1; len1 <= n / 2; ++len1) {
            for (size_t len2 = 1; len2 <= (n - len1) / 2; ++len2) {
                if (IsAdditive(num, 0, len1, len2))
                    return true;
            }
        }
        return false;
    }
private:
    size_t n;
    bool IsAdditive(const string& num, size_t start, size_t len1, size_t len2) {
        if (num[start] == '0' && len1 > 1 || num[start + len1] == '0' && len2 > 1)
            return false;
        
        string num3 = AddStrings(num, start, len1, len2);
        size_t len3 = num3.size();

        if (start + len1 + len2 + len3 > n)
            return false;

        size_t start_of_num3 = start + len1 + len2;
        for (size_t i = 0; i < num3.size(); ++i) {
            if (num3[i] != num[start_of_num3 + i])
                return false;
        }
        
        if (num3 != num.substr(start + len1 + len2, len3))
            return false;
        
        if (start + len1 + len2 + len3 == n)
            return true;
        
        return IsAdditive(num, start + len1, len2, len3);
    }

    string AddStrings (const string& num, const int& start, const int& len1, const int& len2) {
        string ans;
        int carry = 0;
        int idx1 = start + len1 - 1, idx2 = start + len1 + len2 - 1;
        while (carry > 0 || idx1 >= start || idx2 >= start + len1) {
            if (idx1 >= start) carry += num[idx1--] - '0';
            if (idx2 >= start + len1) carry += num[idx2--] - '0';
            ans.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {

    Solution sol;
    bool ans = sol.isAdditiveNumber("199100199");
    cout << ans << endl;

    return 0;
}
