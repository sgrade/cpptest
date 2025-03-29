// 2818. Apply Operations to Maximize Score
// https://leetcode.com/problems/apply-operations-to-maximize-score/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Monotonic Stack & Priority Queue
class Solution {
    public:
        int maximumScore(vector<int>& nums, int k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            n = nums.size();
            prime_scores.resize(n);
            for (int i = 0; i < n; ++i) {
                int num = nums[i];
                for (int factor = 2; factor <= sqrt(num); ++factor) {
                    if (num % factor == 0) {
                        ++prime_scores[i];
                        while (num % factor == 0)
                            num /= factor;
                    }
                }
                if (num >= 2)
                    ++prime_scores[i];
            }

            vector<int> next_dominant(n, n), prev_dominant(n, -1);
            stack<int> decreasing_scores;
            for (int i = 0; i < n; ++i) {
                while (!decreasing_scores.empty() && prime_scores[decreasing_scores.top()] < prime_scores[i]) {
                    int top_idx = decreasing_scores.top();
                    decreasing_scores.pop();
                    next_dominant[top_idx] = i;
                }
                if (!decreasing_scores.empty())
                    prev_dominant[i] = decreasing_scores.top();
                decreasing_scores.emplace(i);
            }

            vector<long long> subarrays(n);
            for (int i = 0; i < n; ++i) {
                subarrays[i] = (long long)(next_dominant[i] - i) * (i - prev_dominant[i]);
            }

            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < n; ++i)
                pq.emplace(nums[i], i);

            long long score = 1;
            while (k > 0) {
                auto [num, i] = pq.top();
                pq.pop();
                long long operations = min((long long)k, subarrays[i]);
                score = (score * power(num, operations)) % MOD;
                k -= operations;
            }

            return score;

        }

    private:
        const int MOD = 1e9 + 7;
        int n;
        vector<int> prime_scores;
        long long power(long long base, long long exponent) {
            long long res = 1;
            while (exponent > 0) {
                if (exponent % 2 == 1)
                    res = ((res * base) % MOD);
                base = (base * base) % MOD;
                exponent /= 2;
            }
            return res;
        }
    };
