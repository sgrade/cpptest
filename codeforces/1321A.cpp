// A. Contest for Robots

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> r(n), b(n);
    for (auto &el: r) {
        cin >> el;
    }
    for (auto &el: b) {
        cin >> el;
    }

    int ans = 0;

    // Editorial - https://codeforces.com/blog/entry/74431
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (r[i] > b[i]) {
            ++x;
        }
        else if (r[i] < b[i]) {
            ++y;
        }
    }

    if (x == 0) {
        ans = -1;
    }
    else {
        ans = ((y + 1) + x - 1) / x;
    }

    cout << ans << endl;

    return 0;
}
