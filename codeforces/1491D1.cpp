// // D1. Sage's Birthday (easy version)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &el: a) {
        cin >> el;
    }

    sort(begin(a), end(a));

    // Idea - https://codeforces.com/contest/1419/submission/144013094

    int ans = (n + 1) / 2 - 1;
    
    vector<int> not_cheap, cheap;

    for (int i = n/2; i < n; ++i) {
        not_cheap.push_back(a[i]);
    }
    for (int i = 0; i < n/2; ++i) {
        cheap.push_back(a[i]);
    }

    cout << ans << '\n';
    for (int i = 0; i < n/2; ++i) {
        cout << not_cheap[i] << ' ' << cheap[i] << ' ';
    }
    if (n % 2 == 1) {
        cout << *rbegin(not_cheap);
    }
    cout << '\n';

    return 0;
}
