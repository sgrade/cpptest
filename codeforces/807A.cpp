// A. Is it rated?

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int n;
    cin >> n;

    string ans = "unrated";

    int a, b;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a != b) {
            ans = "rated";
            break;
        }

        ab[i].first = a;
        ab[i].second = b;
    }

    if (ans == "unrated") {
        if (is_sorted(rbegin(ab), rend(ab))) {
            ans = "maybe";
        }
    }

    cout << ans << endl;

    return 0;
}
