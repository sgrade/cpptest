// B. Flip the Bits

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        
        string a, b;
        getline(cin >> ws, a);
        getline(cin >> ws, b);

        bool ans = true;
        
        int i = 0;
        int cnt = 0;
        for (; i < n; ++i) {
            if (a[i] == '1') {
                ++cnt;
            }
            else {
                --cnt;
            }

            if ((a[i] == b[i]) != (a[i+1] == b[i+1])) {
                // Editorial - https://codeforces.com/blog/entry/89319
                if (cnt != 0) {
                    ans = false;
                    break;
                }
            }
        }
        
        if (n % 2 != 0 && a[n-1] != b[n-1]) {
            ans = false;
        }
    
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
