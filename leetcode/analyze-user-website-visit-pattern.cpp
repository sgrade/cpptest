// 1152. Analyze User Website Visit Pattern
// https://leetcode.com/problems/analyze-user-website-visit-pattern/

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;


struct Node {
    string user;
    int timestamp;
    string website;
};

bool cmp(const Node& node1, const Node& node2) {
    return node1.timestamp < node2.timestamp;
}

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();

        vector<Node> nodes;
        for (int i = 0; i < n; ++i) {
            string u = username[i], w = website[i];
            int t = timestamp[i];
            nodes.emplace_back(u, t, w);
        }

        sort(nodes.begin(), nodes.end(), cmp);

        for (const auto& [u, _, w]: nodes) {
            all_user_visits[u].emplace_back(w);
        }

        for (const auto& [u, v]: all_user_visits) {
            unordered_set<string> patterns;
            for (int i = 0; i < v.size(); ++i) {
                for (int j = i + 1; j < v.size(); ++j) {
                    for (int k = j + 1; k < v.size(); ++k) {
                        string pattern = v[i] + ' ' + v[j] + ' ' + v[k];
                        patterns.emplace(pattern);
                    }
                }
            }
            for (const string& p: patterns) {
                ++counter[p];
            }
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
    unordered_map<string, vector<string>> all_user_visits;
    unordered_map<string, int> counter;
};
