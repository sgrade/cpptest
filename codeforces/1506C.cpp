// C. Double-ended Strings

#include <iostream>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string a, b;
        cin >> a >> b;

        int ans = a.size() + b.size();
        
        string tmp;
        for (int i = 1; i <= min(a.size(), b.size()); ++i) {
            int l = 0;
            while (l + i <= a.size()) {
                tmp = a.substr(l, i);
                if (b.find(tmp) != string::npos) {
                    int candidate = a.size() + b.size() - tmp.size() * 2;
                    ans = min(ans, candidate);
                }
                ++l;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
