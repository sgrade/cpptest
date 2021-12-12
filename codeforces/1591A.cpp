// A. Life of a Flower

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int k = 1;

        bool tmp, prev = false;
        cin >> tmp;
        if (tmp) {
            ++k;
            prev = true;
        }

        for (int i = 1; i < n; ++i) {
            cin >> tmp;
            if (k == -1) {
                continue;
            }
            if (tmp) {
                if (prev) {
                    k += 5;
                }
                else {
                    prev = true;
                    ++k;
                }
            }
            else {
                if (prev) {
                    prev = false;
                }
                else {
                    k = -1;
                }
            }
        }

        cout << k << endl;
    }

    return 0;
}
