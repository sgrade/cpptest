// D. Buying Shovels

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    int t;
    cin >> t;

    while (t--) {
        
        int n, k;
        cin >> n >> k;

        int ans = n;

        if (k >= n) {
            ans = 1;
        }
        else {
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    // Editorial - https://codeforces.com/blog/entry/77846
                    if (i <= k) {
                        ans = min(ans, n / i);
                    }
                    if (n / i <= k) {
                        ans = min(ans, i);
                    }
                }
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
