// A. Equal or Not Equal

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int num_of_N = count(begin(s), end(s), 'N');

        // Editorial - https://codeforces.com/blog/entry/98061

        cout << (num_of_N == 1 ? "NO" : "YES") << endl;
    }

    return 0;
}
