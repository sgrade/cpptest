// A. Equidistant Letters

#include <iostream>
#include <string>
#include <vector>
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

        int n = size(s);

        vector<char> v(begin(s), end(s));
        sort(begin(v), end(v));

        for (auto &ch: v) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}
