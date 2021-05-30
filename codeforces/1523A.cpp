// A. Game of Life
// Time limit exceeded on pretest 2

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        string s;
        getline(cin >> ws, s);

        vector<bool> a(n+2);
        a[0] = 0;
        a[n-1] = 0;
        for (int i = 0; i < n; ++i) {
            a[i+1] = s[i] == '1' ? 1 : 0;
        }

        for (int j = 0; j < m; ++j) {
            vector<bool> b(a);
            for (int i = 1; i < n+1; ++i) {
                a[i] = b[i] || (b[i-1] ^ b[i+1]);
            }
        }

        for (int i = 1; i < n+1; ++i) {
            cout << a[i];
        }
        cout << endl;

    }

    return 0;
}
