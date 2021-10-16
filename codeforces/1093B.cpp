// B. Letters Rearranging

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
        
        map<char, int> cnt;
        for (int i = 0; i < size(s); ++i) {
            ++cnt[s[i]];
        }

        if (size(cnt) == 1) {
            cout << -1 << endl;
        }

        else {
            for (auto &p: cnt) {
                while (p.second--) {
                    cout << p.first;
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
