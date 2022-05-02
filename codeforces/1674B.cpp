// B. Dictionary

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; 

    map<string, int> mp;

    int cnt = 1;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j) continue;

            string tmp;
            tmp.push_back(alphabet[i]);
            tmp.push_back(alphabet[j]);

            mp[tmp] = cnt;

            ++cnt;
        }
    }

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        cout << mp[s] << '\n';
    }

    return 0;
}
