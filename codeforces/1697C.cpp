// C. awoo's Favorite Problem
// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {

        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        map<char, int> s_cnt, t_cnt;

        bool ans = true;
        // int need_b = 0, need_c = true;
        queue<int> need_b, need_c;
        int left, right;

        for (int i = 0; i < n; ++i) {
            ++s_cnt[s[i]];
            ++t_cnt[t[i]];
        }

        for (auto &p: s_cnt) {
            if (p.second != t_cnt[p.first]) {
                ans = false;
                goto ANS;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                
                if(t[i] == 'a') {
                    
                    if (!need_b.empty() && s[i] == 'b') {
                        left = need_b.front();
                        right = i;
                        need_b.pop();
                        swap(s[left], s[right]);
                    }

                    else if (!need_c.empty() && s[i] == 'c') {
                        left = need_c.front();
                        right = i;
                        need_c.pop();
                        swap(s[left], s[right]);
                    }

                    else {
                        ans = false;
                        goto ANS;
                    }
                }
                
                else if (t[i] == 'b') {
                     if (!need_c.empty()) {

                        if (s[i] == 'c') {
                            left = need_c.front();
                            right = i;
                            need_c.pop();
                            swap(s[left], s[right]);
                            continue;
                        }
                        else {
                            ans = false;
                            goto ANS;
                        }
                    }
                    need_b.push(i);
                }
                
                else if (t[i] == 'c') {
                    if (!need_b.empty()) {

                        if (s[i] == 'b') {
                            left = need_b.front();
                            right = i;
                            need_b.pop();
                            swap(s[left], s[right]);
                            continue;
                        }
                        else {
                            ans = false;
                            goto ANS;
                        }
                    }
                    need_c.push(i);
                }
            }
        }

        if (!need_b.empty() || !need_c.empty()) ans = false;

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
