// B. Longest Palindrome

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto &el: a) {
        cin >> el;
    }

    vector<string> b(n);
    string tmp;
    for (int i = 0; i < n; ++i) {
        tmp = a[i];
        reverse(begin(tmp), end(tmp));
        b[i] = tmp;
    }

    vector<int> output;
    int mid = -1;
    vector<bool> taken(n);

    for (int i = 0; i < n; ++i) {
        if (taken[i]) {
            continue;
        }
        bool found_pair = false;
        for (int j = i + 1; j < n; ++j) {
            if (taken[j]) {
                continue;
            }
            if (a[i] == b[j]) {
                found_pair = true;
                taken[i] = true;
                taken[j] = true;
                output.push_back(i);
            }
        }

        if (!found_pair) {
            if (mid == -1) {
                bool flag = true;
                for (int k = 0; k < m/2; ++k) {
                    if (a[i][k] != a[i][m-k-1]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    mid = i;
                    taken[i] = true;
                }
            }
        }
    }

    if (mid == -1 && size(output) == 0) {
        cout << "0\n";
    }

    else {
        int ans = (mid == -1 ? 0 : size(a[mid]));
        for (auto &i: output) {
            ans += size(a[i]) * 2;
        }
        cout << ans << "\n";

        for (auto &i: output) {
            cout << a[i];
        }
        if (mid != -1) {
            cout << a[mid];
        }
        reverse(begin(output), end(output));
        for (auto &i: output) {
            string tmp = a[i];
            reverse(begin(tmp), end(tmp));
            cout << tmp;
        }
        cout << '\n';
    }

    return 0;
}
