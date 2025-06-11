// 3445. Maximum Difference Between Even and Odd Frequency II
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Enumerate Two Characters + Two Pointers
class Solution {
public:
    int maxDifference(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size(), ans = numeric_limits<int>::min();
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b)
                    continue;
                vector<int> best {MX, MX, MX, MX};
                int cnt_a = 0, cnt_b = 0, prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    if (s[right] == a)
                        ++cnt_a;
                    else if (s[right] == b)
                        ++cnt_b;
                    while (right - left >= k && cnt_b - prev_b > 1) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] = min(best[left_status], prev_a - prev_b);
                        ++left;
                        if (s[left] == a)
                            ++prev_a;
                        else if (s[left] == b)
                            ++prev_b;
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != MX)
                        ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                }
            }
        }
        return ans;
    }
private:
    const int MX = numeric_limits<int>::max();
    int getStatus(int cnt_a, int cnt_b) {
        return (cnt_a & 1) << 1 | cnt_b & 1;
    }
};
