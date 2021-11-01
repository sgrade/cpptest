// B. XOR Specia-LIS-t

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        bool ans = false;

        // Editorial - https://codeforces.com/blog/entry/96460
        
        if (n % 2 == 0) {
            ans = true;
        }

        else {
            for (int i = 1; i < n; ++i) {
                if (a[i-1] >= a[i]) {
                    ans = true;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
