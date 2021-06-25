// C. Diluc and Kaeya

#include <iostream>
#include <map>
#include <string>
#include <numeric>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        int d = 0, k = 0;

        // Editorial - https://codeforces.com/blog/entry/91520
        map<pair<int, int>, int> mp;
        for (auto &ch: s) {
            if (ch == 'D') {
                ++d;
            }
            else {
                ++k;
            }

            int g = gcd(d, k);
            pair<int, int> p(d/g, k/g);
            ++mp[p];

            cout << mp[p] << ' ';
        }

        cout << endl;

    }

    return 0;
}
