// 3591. Check if Any Element Has Prime Frequency
// https://leetcode.com/problems/check-if-any-element-has-prime-frequency/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const int& num: nums)
            ++freq[num];
        for (const auto& [_, f]: freq) {
            if (isPrime(f))
                return true;
        }
        return false;
    }
private:
    bool isPrime (int num) {
        if (num < 2)
            return false;
        if (num == 2 || num == 3)
            return true;
        if (num % 2 == 0)
            return false;
        for (int divisor = 3; divisor * divisor <= num; divisor += 2) {
            if (num % divisor == 0)
                return false;
        }
        return true;
    }
};
