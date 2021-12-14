// A. Phone Code

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<char> ans(begin(s), end(s));
    int last = size(s) - 1;

    for (int i = 1; i < n; ++i) {
        cin >> s;
        for (int j = last; j > -1; --j) {
            if (s[j] != ans[j]) {
                last = j - 1;
            }
        }
    }

    cout << last + 1 << endl;

    return 0;
}
