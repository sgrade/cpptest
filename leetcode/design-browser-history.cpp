// 1472. Design Browser History
// https://leetcode.com/problems/design-browser-history/

#include <bits/stdc++.h>

using namespace std;


class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.emplace_back(homepage);
    }
    
    void visit(string url) {
        if (cur_idx < max_idx) {
            history.erase(history.begin() + cur_idx + 1, history.end());
        }
        history.emplace_back(url);
        max_idx = ++cur_idx;
    }
    
    string back(int steps) {
        cur_idx = max(0, cur_idx - steps);
        return history[cur_idx];
    }
    
    string forward(int steps) {
        cur_idx = min(max_idx, cur_idx + steps);
        return history[cur_idx];
    }

private:
    vector<string> history;
    int cur_idx = 0, max_idx = 0;
};


int main() {
    BrowserHistory bh("leetcode.com");
    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");
    cout << bh.back(1) << endl;
    cout << bh.back(1) << endl;
    cout << bh.forward(1) << endl;
    bh.visit("linkedin.com");
    cout << bh.forward(2) << endl;
    cout << bh.back(2) << endl;
    cout << bh.back(7) << endl;
}