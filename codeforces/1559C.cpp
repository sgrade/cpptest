// C. Mocha and Hiking

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        vector<int> output;

        // Editorial - https://codeforces.com/blog/entry/93898

        if (a[0]) {
            output.push_back(n+1);
            for (int i = 1; i < n+1; ++i) {
                output.push_back(i);
            }
        }

        else if (!a[n-1]) {
            for (int i = 1; i < n+1; ++i) {
                output.push_back(i);
            }
            output.push_back(n+1);
        }

        else {
            bool stop = false;
            for (int i = 0; i < n; ++i) {
                if (!a[i] && a[i+1]) {
                    for (int j = 0; j <= i; ++j) {
                        output.push_back(j+1);
                    }
                    output.push_back(n+1);
                    for (int j = i+1; j < n; ++j) {
                        output.push_back(j+1);
                    }
                    stop = true;
                    break;
                }
                if (stop) {
                    break;
                }
            }
        }

        for (auto &village: output) {
            cout << village << ' ';
        }
        cout << endl;
    }

    return 0;
}
