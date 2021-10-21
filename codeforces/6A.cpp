// A. Triangle

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    vector<int> v(4);
    for (auto &el: v) {
        cin >> el;
    }

    string ans = "IMPOSSIBLE";

    // Theory behind - https://www.geeksforgeeks.org/possible-form-triangle-array-values/
    for (int a = 0; a < 4; ++a) {

        for (int b = 0; b < 4; ++b) {
            if (a == b) {
                continue;
            }

            for (int c = 0; c < 4; ++c) {
                if (a == c || b == c) {
                    continue;
                }

                if (v[a] + v[b] > v[c] && v[b] + v[c] > v[a] && v[a] + v[c] > v[b]) {
                    ans = "TRIANGLE";
                    goto PRINT_ANS;
                }

                if (v[a] + v[b] == v[c] || v[b] + v[c] == v[a] || v[a] + v[c] == v[b]) {
                    ans = "SEGMENT";
                }
            }
        }
    }

    PRINT_ANS:
    cout << ans << endl;

    return 0;
}
