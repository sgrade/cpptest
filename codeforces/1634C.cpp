// C. OKEA

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        // Editorial - https://codeforces.com/blog/entry/99563
        
        if (n % 2 == 0 || k == 1) {
            cout << "YES\n";
            vector<int> even_odd = {2, 1};
            int flag;
            for (int i = 1; i < n + 1; ++i) {
                flag = i % 2;
                for (int j = 0; j < k; ++j) {
                    cout << even_odd[flag] << ' ';
                    even_odd[flag] += 2;
                }
                cout << '\n';
            }
        }
        
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
