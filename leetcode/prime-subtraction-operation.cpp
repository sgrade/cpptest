// 2601. Prime Subtraction Operation
// https://leetcode.com/problems/prime-subtraction-operation/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Storing the primes
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int mx = *max_element(nums.begin(), nums.end());
        vector<int> prev_prime(mx + 1);
        for (int i = 2; i <= mx; ++i) {
            if (is_prime(i))
                prev_prime[i] = i;
            else
                prev_prime[i] = prev_prime[i - 1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            int bound;
            if (i == 0)
                bound = nums[0];
            else
                bound = nums[i] - nums[i - 1];
            if (bound <= 0)
                return false;

            int largest_prime = prev_prime[bound - 1];
            nums[i] = nums[i] - largest_prime;
        }
        return true;
    }
private:
    bool is_prime(int x) {
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
};
