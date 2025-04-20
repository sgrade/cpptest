// 781. Rabbits in Forest
// https://leetcode.com/problems/rabbits-in-forest/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach #1: Count
//  and https://leetcode.com/problems/rabbits-in-forest/solutions/6669671/beats-super-easy-beginners-java-c-c-python-javascript-dart/
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            vector<int> counter(1000);
            for (const int& answer: answers)
                ++counter[answer];
            int ans = 0;
            for (int i = 0; i < 1000; ++i) {
                int group_size = i + 1;
                int groups = (counter[i] + i) / group_size;
                ans += groups * group_size;
            }
            return ans;
        }
    };
