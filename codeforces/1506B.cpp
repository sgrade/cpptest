// B. Partial Replacement

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s;
        getline(cin >> ws, s);

        int ans = 1;
        
        size_t i, j;
        i = s.find('*');
        j = s.rfind('*');

        if (i != j) {
            ans = 2;

            string tmp;
            while (true) {
                tmp = s.substr(i+1, k);
                int x = tmp.find_last_of('*');
                i += x + 1;
                if (i != string::npos) {
                    if (i < j) {
                        ++ans;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
