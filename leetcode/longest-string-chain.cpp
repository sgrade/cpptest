// 1048. Longest String Chain
// https://leetcode.com/problems/longest-string-chain/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& word1, const string& word2){
            return word1.size() < word2.size();
        });
        
        int ans = 1;
        
        unordered_map<string, int> dp;
        
        for (const string& word: words) {
            int cur_ans = 1;
            string pred;
            for (int i = 0; i < word.size(); ++i) {
                pred = word.substr(0, i) + word.substr(i + 1, string::npos);
                if (dp.find(pred) != dp.end()) {
                    cur_ans = max(cur_ans, dp[pred] + 1);
                }
            }
            dp[word] = cur_ans;
            ans = max(ans, cur_ans);
        }
        
        return ans;
    }
};


int main() {

    Solution sol;
    vector<string> input = {"a","b","ba","bca","bda","bdca"};

    cout << sol.longestStrChain(input) << endl;

    return 0;
}
