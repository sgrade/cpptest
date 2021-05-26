// B1. Palindrome Game (easy version)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        int zeroes = count(begin(s), end(s), '0');

        string a = "ALICE", b = "BOB";
        string ans;

        // Editorial - https://codeforces.com/blog/entry/90939

        if (zeroes % 2 != 0) {
            ans = zeroes==1 ? b : a;
        }
        else {
            ans = b;
        }

        cout << ans << endl;
    }

    return 0;
}
