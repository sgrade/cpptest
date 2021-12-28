// A. Construct a Rectangle

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> a(3);
        for (auto &el: a) {
            cin >> el;
        }

        bool ans = false;
        
        for (int i = 0; i < 3; ++i) {
            // Some ideas are from https://codeforces.com/blog/entry/98453
            if (a[i] == a[(i + 1) % 3] + a[(i + 2) % 3]) {
                ans = true;
            }
            if (ans) {
                break;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (a[i] % 2 == 0) {
                int tmp = a[i] / 2;
                if (a[(i + 1) % 3] == a[(i + 2) % 3]) {
                    ans = true;
                }
            }
            if (ans) {
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
