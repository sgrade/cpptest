// 395. Longest Substring with At Least K Repeating Characters
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Sliding Window
class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int ans = 0;
        set<char> uniq(s.begin(), s.end());
        
        for (int uniq_need = 1; uniq_need <= uniq.size(); ++uniq_need) {
            vector<int>  counter(26);
            int left = 0, right = 0, idx = 0, uniq_count = 0, count_at_least_k = 0;
            while (right < s.size()) {
                if (uniq_count <= uniq_need) {
                    idx = s[right] - 'a';
                    ++counter[idx];
                    if (counter[idx] == 1) 
                        ++uniq_count;
                    if (counter[idx] == k) 
                        ++count_at_least_k;
                    ++right;
                }
                else {
                    idx = s[left] - 'a';
                    --counter[idx];
                    if (counter[idx] == 0) 
                        --uniq_count;
                    if (counter[idx] == k - 1) 
                        --count_at_least_k;
                    ++left;
                }
                
                if (uniq_count == uniq_need && uniq_count == count_at_least_k) {
                    ans = max(right - left, ans);
                }
            }
        }
        
        return ans;
    }
};
