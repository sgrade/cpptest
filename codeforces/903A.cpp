// A. Hungry Student Problem

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {

        int x;
        cin >> x;

        bool ans = false;

        int a, b;
        for (a = 0; a < 34; ++a) {
            for (b = 0; b < 25; ++b) {
                if (a * 3 + b * 7 == x) {
                    ans = true;
                    goto ANS;
                }
            }
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
