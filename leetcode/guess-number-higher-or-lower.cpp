// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/

#include <bits/stdc++.h>

using namespace std;


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
 int guess(int num);
 

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid, current;
        while (left <= right) {
            mid = left + (right - left) / 2;
            current = guess(mid);
            if (current == 0) {
                return mid;
            }
            else if (current == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
