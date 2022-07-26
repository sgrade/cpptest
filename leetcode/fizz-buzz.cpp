// 412. Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (int i = 1; i <= n; ++i) {
            string current_ans;
            if (i % 3 == 0) 
                current_ans += "Fizz";
            if (i % 5 == 0)
                current_ans += "Buzz";
            if (current_ans.empty())
                current_ans += to_string(i);
            ans[i - 1] = current_ans;
        }
        return ans;
    }
};
