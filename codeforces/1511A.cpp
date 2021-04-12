// 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int r[n];
        for (auto &el: r) {
            cin >> el;
        }

        int u1 = 0, u2 = 0, d1 = 0, d2 = 0;

        for (int i = 0; i < n; ++i) {
            if (r[i] == 1) {
                if (u1 > u2) {
                    ++u2;
                }
                else {
                    ++u1;
                }
            }

            else if (r[i] == 2) {
                if (u1 > d1) {
                    ++d1;
                }
                else if (u2 > d2) {
                    ++d2;
                }
                else {
                    if (d1 >= d2) {
                        ++d1;
                    }
                    else {
                        ++d2;
                    }
                }
            }

            else {
                if (u1 >= d1) {
                    ++u1;
                }
                else if (u2 >= d2) {
                    ++u2;
                }
                else {
                    ++u1;
                }
            }
        }

        cout << u1 + u2 << endl;

    }

    return 0;
}
