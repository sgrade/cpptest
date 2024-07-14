// 726. Number of Atoms
// https://leetcode.com/problems/number-of-atoms/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string countOfAtoms(string formula) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = formula.size();
        int left = 0, right = 0;

        st.emplace(unordered_map<string, int>());
        int idx = 0;
        while (idx < n) {
            char ch = formula[idx];
            if (ch == '(') {
                st.emplace(unordered_map<string, int>());
                ++idx;
            }
            else if (ch == ')') {
                ++idx;
                ch = formula[idx];
                if (!isdigit(ch))
                    unpack_top(1);
            }
            else if (isupper(ch)) {
                string name = get_name(formula, idx);
                int cnt;
                ch = formula[idx];
                if (idx < n && isdigit(ch))
                    cnt = get_cnt(formula, idx);
                else
                    cnt = 1;
                st.top()[name] += cnt;
            }
            else if (isdigit(ch)) {
                int current_cnt = get_cnt(formula, idx);
                unpack_top(current_cnt);
            }
        }

        string ans;
        map<string, int> sorted (st.top().begin(), st.top().end());
        for (const auto& [el, cnt]: sorted) {
            ans += el;
            if (cnt > 1)
                ans += to_string(cnt);
        }
        return ans;
    }

private:
    int n;
    stack <unordered_map<string, int>> st;

    string get_name (const string& formula, int& idx) {
        string element = "";
        element += formula[idx++];
        while (idx < n && islower(formula[idx]))
            element += formula[idx++];
        return element;
    }

    int get_cnt (const string& formula, int& idx) {
        int cnt = 0;
        while (idx < n && isdigit(formula[idx])){
            cnt *= 10;
            cnt += formula[idx++] - '0';
        }
        return cnt;
    }

    void unpack_top (const int& current_cnt) {
        unordered_map<string, int> current_counter = st.top();
        st.pop();
        for (auto& [_, cnt]: current_counter)
            cnt *= current_cnt;
        for (auto& [element, cnt]: current_counter)
            st.top()[element] += cnt;
    }
};
