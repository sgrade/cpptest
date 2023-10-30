// C. Qingshan Loves Strings 2

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> ans;

        if (n % 2 != 0) {
            cout << "-1\n";
            continue;
        }

        int zeroes = 0, ones = 0;
        deque<char> q;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')
                ++zeroes;
            else
                ++ones;
            q.emplace_back(s[i]);
        }

        if (zeroes != ones) {
            cout << "-1\n";
            continue;
        }

        int idx = 0;
        while (!q.empty()) {
            if (q.front() == q.back()) {
                if (q.front() == '0') {
                    q.emplace_back('0');
                    q.emplace_back('1');
                    ans.emplace_back(n - idx);
                }
                else {
                    q.emplace_front('1');
                    q.emplace_front('0');
                    ans.emplace_back(idx);
                }
                n += 2;
            }
            while (!q.empty() && q.front() != q.back()) {
                q.pop_front();
                q.pop_back();
                ++idx;
            }
        }

        cout << ans.size() << '\n';
        for (const int& el: ans)
            cout << el << ' ';
        cout << "\n";

    }

    return 0;
}
