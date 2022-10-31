// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> ans{"/"};
        vector<int> shift;
        for (int i = 1; i < n; ++i) {
            if (path[i] == '/') {
                if (ans.back() == "/") {
                    continue;
                }
                ans.emplace_back("/");
                shift = CountRepetitions(i, n, path);
                if (shift[0] != 0) {
                    i = shift[1] - 1;
                }
            }
            
            else if (path[i] == '.') {
                shift = CountRepetitions(i, n, path);
                
                if (ans.back() != "/" || shift[0] > 1 || (shift[1] < n && isalpha(path[shift[1]]))) {
                    if (ans.back() == "/") {
                        ans.emplace_back("");
                    }
                    ans.back() += path.substr(i, shift[1] - i);
                    i = shift[1] - 1;
                }
                
                else if (shift[0] == 0) {
                    if (i + 1 == n) {
                        break;
                    }
                    else if (i + 1 == '/') {
                        if (ans.back() == "/") {
                            continue;
                        }
                    }
                }
                
                else if (shift[0] == 1) {
                    ++i;
                    if (ans.back() == "/") {
                        if (ans.size() > 2) {
                            ans.pop_back();
                            ans.pop_back();
                        }
                        continue;
                    }
                }
            }
            
            else {
                if (ans.back() == "/") {
                    ans.emplace_back("");
                }
                ans.back() += path[i];
            }
        }
        
        if (ans.size() > 1 && ans.back() == "/") {
            ans.pop_back();
        }
        
        path = "";
        for (const string &s: ans) {
            path += s;
        }
        return path;
    }
private:
    vector<int> CountRepetitions(const int &i, const int &n, const string &path) {
        int repetitions = 0, j;
        for (j = i + 1; j < n; ++j) {
            if (path[j] == path[i]) {
                ++repetitions;
            }
            else {
                break;
            }
        }
        return vector<int>{repetitions, j};
    }
};
