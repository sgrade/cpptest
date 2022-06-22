// C. Where's the Bishop?

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    string s;

    while (t--) {

        int x, r, c;
        
        int flag = -1;
        for (int i = 1; i < 9; ++i) {
            cin >> s;
            x = count(s.begin(), s.end(), '#');
            if (x == 2) {
                if (flag == -1) {
                    flag = 1;
                }
            }
            else if (x == 1) {
                if (flag == 1) {
                    r = i;
                    c = s.find('#') + 1;
                    flag = 2;
                }
            }
        }

        cout << r << ' ' << c << '\n';
    }

    return 0;
}
