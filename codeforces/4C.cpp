// C. Registration system

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int n;
    cin >> n;

    map<string, int> mp;
    string tmp;
    while (n--) {
        getline(cin >> ws, tmp);
        auto found = mp.find(tmp);
        if (found != mp.end()) {
            ++mp[tmp];
            cout << tmp << mp[tmp] << endl;
        }
        else {
            mp.insert(pair<string, int>(tmp, 0));
            cout << "OK" << endl;
        }
    }

    return 0;
}
