// A. Important Exam

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (auto &el: s) {
        cin >> el;
    }
    vector<int> a(m);
    for (auto &el: a) {
        cin >> el;
    }

    int ans = 0;
    
    for (int j = 0; j < m; ++j) {
        map<char, int> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i][j]];
        }
        int mx = 0;
        for (auto &el: cnt) {
            mx = max(mx, el.second);
        }
        ans += a[j] * mx;
    }

    cout << ans << endl;

    return 0;
}
