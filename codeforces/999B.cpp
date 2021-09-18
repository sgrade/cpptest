// B. Reversing Encryption

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    string s;
    cin >> n >> s;

    // Editorial - https://codeforces.com/blog/entry/60138

    vector<char> sv(begin(s), end(s));

    for (int i = 1; i <=n; ++i) {
        if (n % i == 0) {
            reverse(begin(sv), begin(sv) + i);
        }
    }

    for (auto &ch: sv) {
        cout << ch;
    }
    cout << endl;

    return 0;
}
