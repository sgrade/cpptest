// 564. Find the Closest Palindrome
// https://leetcode.com/problems/find-the-closest-palindrome/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Binary Search
class Solution {
public:
    string nearestPalindromic(string n) {
        len = n.size();
        long long num = stoll(n);
        long long prev = GetPrevousPalindrome (num);
        long long nxt = GetNextPalindrome (num);
        if (abs(nxt - num) <= abs(prev - num))
            return to_string(nxt);
        return to_string(prev);
    }

private:
    int len;
    
    long long GetPrevousPalindrome (long long& num) {
        long long left = num, right = 1e18;
        long long ans = INT_MIN;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long pal = Convert(mid);
            if (pal > num) {
                ans = pal;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

    long long GetNextPalindrome (long long& num) {
        long long left = 0, right = num;
        long long ans = INT_MIN;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long pal = Convert(mid);
            if (pal < num) {
                ans = pal;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }

    long long Convert (long long& num) {
        string s = to_string(num);
        int n = s.size();
        int left = (n - 1) / 2, right = n / 2;
        while (left >= 0)
            s[right++] = s[left--];
        return stoll(s);
    }
};
