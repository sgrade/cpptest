// 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (left == letters.size() - 1 && letters.back() <= target)
            return letters.front();
        return letters[left];
    }
};
