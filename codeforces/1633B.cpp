// B. Minority

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int zeroes = count(begin(s), end(s), '0');
        int ones = size(s) - zeroes;

        int ans = 0;

        if (zeroes == ones) {
            if (size(s) != 1) {
                ans = zeroes - 1;
            }
        }
        
        else {
            ans = min(zeroes, ones);
        }
        
        cout << ans << '\n';
    }

    return 0;
}
