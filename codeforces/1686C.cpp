// C. Circular Local MiniMax
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        sort(a.begin(), a.end());

        bool ans = true;
        
        int left = -1;

        for (int i = 1; i < n; ++i) {

            if (a[i-1] < a[i]) {
                if (left == -1) {
                    left = i;
                }
                else {
                    continue;
                }
            }

            else if (a[i-1] == a[i]) {

                if (left != -1) {
                    swap(a[i], a[left]);
                    if (left + 2 < i - 1) {
                        left = i + 2;
                    }
                    else {
                        left = -1;
                    }
                }

                else {
                    bool found = false;
                    for (int j = i + 1; j < n; ++j) {
                        if (a[i] < a[j]) {
                            found = true;
                            swap(a[i], a[j]);
                            break;
                        }
                    }
                    if (!found) {
                        ans = false;
                        break;
                    }
                }
            }

            else {
                continue;
            }
        }

        if (ans) {

            for (int i = 1; i < n - 1; i += 2) {
                
                if (a[i] < a[i+1]) {
                    swap(a[i], a[i+1]);
                }
                else {
                    ans = false;
                    break;
                }
            }

            if (a[n-1] <= a[0]) {
                ans = false;
            }
        }

        if (!ans) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (int &el: a) {
                cout << el << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
