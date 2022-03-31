// A. Playoff

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int ans = 1;

        while (n--) {
            ans = ans << 1;
        }

        cout << ans - 1 << '\n';
    }

    return 0;
}
