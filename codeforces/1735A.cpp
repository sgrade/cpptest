// A. Working Week

#include <iostream>
#include <vector>
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

        int ans = (n - 3) / 3 - 1;

        cout << ans << '\n';
    }

    return 0;
}
