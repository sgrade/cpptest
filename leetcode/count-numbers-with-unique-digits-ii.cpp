// 3032. Count Numbers With Unique Digits II
// https://leetcode.com/problems/count-numbers-with-unique-digits-ii/


// Based on https://leetcode.com/problems/count-numbers-with-unique-digits-ii/solutions/5898091/dp-bitmask
class Solution {
public:
    int numberCount(int a, int b) {
        if (a > b) {
            return 0;
        }
        return numberCount(a + 1, b) + isUnique(a);
    }
private:
    bool isUnique (int x) {
        int mask = 0;
        while (x) {
            int rem = x % 10;
            x /= 10;
            if ((mask >> rem) & 1) {
                return false;
            }
            mask |= (1 << rem);
        }
        return true;
    }
};
