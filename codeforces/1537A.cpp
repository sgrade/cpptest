// A. Arithmetic Array

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int sm = 0;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            sm += tmp;
        }

        int ans = 0;

        if (sm != n) {
            if (sm < n) {
                ans = 1;
            }
            else {
                ans = sm - n;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
