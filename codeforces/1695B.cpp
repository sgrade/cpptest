// B. Circle Game

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        string ans = "Mike";

        if (n % 2 != 0) {
            ans = "Mike";
        }

        else {
            auto mn_it = min_element(a.begin(), a.end());
            int d = distance(a.begin(), mn_it);
            if (d % 2 == 0) {
                ans = "Joe";
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
