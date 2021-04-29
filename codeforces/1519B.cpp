// B. The Cake Is a Lie

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        bool ans = false;

        int cost = (n - 1) + n * (m - 1);
        if (cost == k) {
            ans = true;
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
