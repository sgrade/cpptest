// A. Marathon

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        vector<int> abcd(4);
        for (int &el: abcd) cin >> el;

        int ans = 0;
        for (int i = 1; i < 4; ++i) {
            if (abcd[i] > abcd[0]) ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
