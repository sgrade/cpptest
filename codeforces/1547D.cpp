// D. Co-growing Sequence
 
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
 
        vector<int> x(n);
        for (auto &el: x) {
            cin >> el;
        }
 
        vector<int> y(n);

        // Editorial - https://codeforces.com/blog/entry/92715

        int t;
        for (int i = 1; i < n; ++i) {
            t = x[i-1] ^ y[i-1];
            y[i] = (t | x[i]) ^ x[i];
        }

        for (int i = 0; i < n; ++i) {
            cout << y[i] << ' ';
        }
        cout << endl;
    }
 
    return 0;
}
