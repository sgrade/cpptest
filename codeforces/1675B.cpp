// B. Make It Increasing

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

        vector<int> a(n);
        for (int &el: a) cin >> el;

        long long ops = 0;
       
        for (int i = n-2; i > -1; --i) {
            while (a[i] >= a[i+1]) {
                a[i] /= 2;
                ++ops;
                if (a[i] == 0) {
                    if (i != 0 || a[i] == a[i+1]) {
                        ops = -1;
                    }
                    goto ANS;
                }
            }
        }

        ANS:
        cout << ops << '\n';
    }

    return 0;
}
