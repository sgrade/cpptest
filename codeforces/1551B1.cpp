// B1. Wonderful Coloring - 1

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        map<char, int> mp;
        for (auto &ch: s) {
            ++mp[ch];
        }

        float ans = 0;
        for (auto &pair: mp) {
            if (pair.second == 1) {
                ans += 0.5;
            }
            else {
                ans += 1;
            }
        }

        cout << (int) ans << endl;

    }

    return 0;
}
