// 1152. Analyze User Website Visit Pattern
// https://leetcode.com/problems/analyze-user-website-visit-pattern/

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;


// Wrong answer
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        for (int i = 0; i < username.size(); ++i) {
            string u = username[i], w = website[i];
            int t = timestamp[i];
            updatePattern(u, w);
        }
        int mx = 0;
        string pattern;
        for (auto& [p, cnt]: counter) {
            if (cnt < mx || (cnt == mx && p > pattern)) {
                continue;
            }
            mx = cnt;
            pattern = p;
        }
        vector<string> ans;
        string tmp;
        istringstream iss(pattern);
        while (iss >> tmp) {
            ans.emplace_back(tmp);
        }
        return ans;
    }

private:
    unordered_map<string, vector<string>> user_to_pattern;
    unordered_map<string, int> counter;

    void updatePattern(string u, string w) {
        if (user_to_pattern.find(u) == user_to_pattern.end()) {
            user_to_pattern[u] = vector<string>(3);
        }
        vector<string>& p = user_to_pattern[u];
        rotate(p.begin(), p.begin() + 2, p.end());
        p[2] = w;
        if (p[0] != "") {
            string pattern = p[0] + ' ' + p[1] + ' ' + p[2];
            ++counter[pattern];
        }
    }
};
