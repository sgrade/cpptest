// B. Balls of Buma

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    string s;
    cin >> s;

    int n = size(s);

    char prev = s[0];
    vector<pair<char, int>> v;
    v.push_back(pair<char, int>(prev, 1));

    for (int i = 1; i < n; ++i) {
        if (s[i] == prev) {
            ++rbegin(v)->second;
        }
        else {
            v.push_back(pair<char, int>(s[i], 1));
            prev = s[i];
        }
    }

    int ans = 0;

    // Editorial - http://nerc.itmo.ru/archive/2019/nerc-2019-tutorial.pdf
    if (size(v) % 2 != 0) {
        int m = size(v) / 2;
        if (v[m].second > 1) {
            int i = 1;
            ans = v[m].second - 1 + 2;
            while (m - i > -1) {
                if ((v[m-i].first == v[m+i].first) && (v[m-i].second + v[m+i].second) > 2) {
                    ++i;
                }
                else {
                    ans = 0;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
