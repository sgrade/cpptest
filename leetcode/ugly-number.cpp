// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        vector<int> factors = allPrimeFactors(n);
        for (const int& factor: factors) {
            if (factor == 2 || factor == 3 || factor == 5) {
                continue;
            }
            return false;
        }
        return true;
    }

private:
    vector<int> allPrimeFactors (int n){
        // Source - https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
        
        vector<int> v;
        if (n == 0 || n == 1) return v;

        while(n % 2 == 0){
            v.push_back(2);
            n /= 2;
        }

        for (int i=3; i <= sqrtl(n); i += 2){
            while (n % i == 0){
                v.push_back(i);
                n = n/i;
            }
        }
        
        if (n > 2) v.push_back(n);

        return v;

    }
};
