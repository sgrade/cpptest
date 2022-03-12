// A. Competitive Programmer

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {

        string y;
        cin >> y;

        // Editorial - https://codeforces.com/blog/entry/72243

        int sm = 0, zeroes = 0, even = 0, x;

        for (int i = 0; i < size(y); ++i) {
            
            if (y[i] == '0') {
                ++zeroes;
            }

            x = y[i] - '0';

            sm += x;

            if (x % 2 == 0) {
                ++even;
            }
        }

        bool ans = false;

        if (sm % 3 == 0 && zeroes > 0 && even > 1) {
            ans = true;
        }

        cout << (ans ? "red\n" : "cyan\n");

    }

    return 0;
}
