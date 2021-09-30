// C. Yet Another Broken Keyboard

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<char> c(k);
    for (auto &ch: c) {
        cin >> ch;
    }

    long long ans = 0;

    long long d = 0;
    vector<char>::iterator it;

    for (int i = 0; i < n; ++i) {
    
        it = find(begin(c), end(c), s[i]);
    
        if (it == end(c)) {
            // Number of substrings in string = n * (n+1) / 2
            // https://www.geeksforgeeks.org/number-substrings-string/
            ans += d * (d+1) / 2;
            d = 0;
        }

        else {
            ++d;
        }
    }

    if (d) {
        ans += d * (d+1) / 2;
    }

    cout << ans << '\n';

    return 0;
}
