// B. Make AP

#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;

    while (t--) {

        int a, b, c;
        cin >> a >> b >> c;

        bool ans = false;

        int d;

        // Editorial - https://codeforces.com/blog/entry/98942

        // changing c
        d = b - a;
        int cc = b + d;
        if (cc > 0 && cc % c == 0 && cc >= c) {
            ans = true;
        }

        // changing b
        if (!ans) {
            if ((c - a) % 2 == 0) {
                d = (c - a) / 2;
                int bb = a + d;
                if (bb > 0 && bb % b == 0 && bb >= b) {
                    ans = true;
                }
            }
        }

        // changing a
        if (!ans) {
            d = c - b;
            int aa = b - d;
            if (aa > 0 && aa % a == 0 && aa >= a) {
                ans = true;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
