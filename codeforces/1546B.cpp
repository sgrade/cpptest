// B. AquaMoon and Stolen String

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        // Editorial - https://codeforces.com/blog/entry/92739

        /*
        char a = 'a';
        char b = 'b';
        cout << char((a ^ b ^ b)) << endl;

        // output:
        a
        */

        vector<char> output(m, 0);
        string tmp;

        for (int i = 0; i < n + n - 1; ++i) {
            getline(cin >> ws, tmp);

            for (int j = 0; j < m; ++j) {
                output[j] ^= tmp[j];
            }
        }

		for (auto &ch: output) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
