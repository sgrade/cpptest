// A. Doggo Recoloring

#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> counter;

    for (int i = 0; i < n; ++i) {
        ++counter[s[i]];
    }

    bool ans = (counter.size() == s.size() ? false : true);
    if (counter.size() == 1) {
        ans = true;
    }

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}
